/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_processes_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:07:07 by pmendez-          #+#    #+#             */
/*   Updated: 2024/08/25 23:30:16 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	first_iteration(t_pipex *pipex, char *command_argv)
{
	pipex->fd[READ] = open(pipex->infile, O_RDONLY);
	if (pipex->fd[READ] == -1)
		error_no_cmd(RED "Error\n" END "Error opening files\n", 1);
	if (access(pipex->infile, R_OK) == -1)
		error_no_cmd(RED "Error\n" END "No read permissions for input\n", 1);
	if (dup2(pipex->fd[READ], STDIN_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1);
	close_fd(&pipex->fd[READ], "pipex->fd[READ]");
	if (dup2(pipex->pipe_father[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1);
	close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");
	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	execute(pipex, command_argv);
}

static void	last_iteration(t_pipex *pipex, char *command_argv)
{
	pipex->fd[WRITE] = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->fd[WRITE] == -1)
		error_no_cmd(RED "Error\n" END "Error opening files\n", 1);
	if (access(pipex->outfile, W_OK) == -1)
		ft_putstr_fd(RED "Error\n" END "No write permissions for output\n", 1);
	if (dup2(pipex->fd[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1);
	close_fd(&pipex->fd[WRITE], "pipex->fd[1]");
	if (dup2(pipex->pipe_father[READ], STDIN_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1);
	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");
	execute(pipex, command_argv);
}

static void	other_iterations(t_pipex *pipex, char *command_argv)
{
	if (dup2(pipex->pipe_father[READ], STDIN_FILENO) == -1)
	{
		close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");
		close_fd(&pipex->pipe_aux[READ], "pipe_aux[READ]");
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1);
	}
	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");
	if (dup2(pipex->pipe_aux[WRITE], STDOUT_FILENO) == -1)
	{
		close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");
		close_fd(&pipex->pipe_aux[READ], "pipe_aux[READ]");
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1);
	}
	close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");
	close_fd(&pipex->pipe_aux[READ], "pipe_aux[READ]");
	execute(pipex, command_argv);
}

static void	move_info(t_pipex *pipex)
{
	if (pipex->index != 0 && pipex->index != pipex->num_cmds - 1)
	{
		close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
		close_fd(&pipex->pipe_aux[WRITE], "pipex->pipe_aux[WRITE]");
		pipex->pipe_father[READ] = pipex->pipe_aux[READ];
	}
}

void	command(t_pipex *pipex, char *argv[], int begin_commands)
{
	if (pipe(pipex->pipe_father) == -1)
		error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
	while (pipex->index < pipex->num_cmds)
	{
		if (pipex->index != 0 && pipex->index != pipex->num_cmds - 1
			&& pipe(pipex->pipe_aux) == -1)
			error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
		pipex->pid = fork();
		if (pipex->pid == -1)
			error_no_cmd(RED "Error\n" END "Error creating child\n", 1);
		else if (pipex->pid == 0)
		{
			if (pipex->index == 0)
				first_iteration(pipex, argv[begin_commands]);
			else if (pipex->index == pipex->num_cmds - 1)
				last_iteration(pipex, argv[begin_commands + pipex->index]);
			else
				other_iterations(pipex, argv[begin_commands + pipex->index]);
		}
		move_info(pipex);
		pipex->index++;
	}
}
