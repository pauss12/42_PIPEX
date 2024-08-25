/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_processes_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:07:07 by pmendez-          #+#    #+#             */
/*   Updated: 2024/08/05 16:07:08 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	first_iteration(t_pipex *pipex, char *argv[])
{
	close_fd(&pipex->pipe_aux[READ], "pipe_aux[READ]");
	close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");
	pipex->fd[READ] = open(argv[1], O_RDONLY);
	if (pipex->fd[READ] == -1)
		error_no_cmd(RED "Error\n" END "Error opening files\n", 1);
	if (access(argv[WRITE], R_OK) == -1)
		error_no_cmd(RED "Error\n" END "No read permissions for input\n", 1);
	if (dup2(pipex->fd[READ], STDIN_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1);
	close_fd(&pipex->fd[READ], "pipex->fd[READ]");
	if (dup2(pipex->pipe_father[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1);
	close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");
	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	execute(pipex, argv[2]);
}

static void	last_iteration(t_pipex *pipex, char *argv[], int argc)
{
	pipex->fd[WRITE] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->fd[WRITE] == -1)
		error_no_cmd(RED "Error\n" END "Error opening files\n", 1);
	if (access(argv[argc - 1], W_OK) == -1)
		ft_putstr_fd(RED "Error\n" END "No write permissions for output\n", 1);
	if (dup2(pipex->fd[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1);
	close_fd(&pipex->fd[WRITE], "pipex->fd[1]");

	if (dup2(pipex->pipe_father[READ], STDIN_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "--dup2 failed in STDIN\n", 1);
	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");
	execute(pipex, argv[argc - 2]);
}

static void other_iterations(t_pipex *pipex, char *argv[])
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

    execute(pipex, argv[2 + pipex->index]);
}

void	command(t_pipex *pipex, char **argv, int argc)
{
	if (pipe(pipex->pipe_father) == -1)
	{
		error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
		exit(1);
	}

	if (pipe(pipex->pipe_aux) == -1)
	{
		error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
		exit(1);
	}

	while (pipex->index < pipex->num_cmds)
	{
		
		if (pipex->index != 0 && pipex->index != pipex->num_cmds - 1)
			pipex->flag = 1;

		pipex->pid = fork();
	
		if (pipex->pid == -1)
			error_no_cmd(RED "Error\n" END "Error creating child\n", 1);
		else if (pipex->pid == 0)
		{
			if (pipex->index == 0)
			{
				dprintf(2, "-- El comando es [%s]\n\n", argv[2]);
				first_iteration(pipex, argv);
			}
			else if (pipex->index == pipex->num_cmds - 1)
			{
				dprintf(2, "\n** El comando es [%s]\n\n", argv[argc - 2]);
				last_iteration(pipex, argv, argc);
			}
			else
			{	
				dprintf(2, "\n!!! El comando es [%s]\n\n", argv[2 + pipex->index]);
				other_iterations(pipex, argv);
			}
		}
		else
		{
			//close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");
			if (pipex->flag == 1)
			{
				dprintf(2, "Esperando al hijo\n");

				dprintf(2, "EN EL HIJO: pipe_father[READ] = %d\n", pipex->pipe_father[READ]);
				dprintf(2, "EN EL HIJO: pipe_father[WRITE] = %d\n", pipex->pipe_father[WRITE]);
				dprintf(2, "EN EL HIJO: pipe_aux[READ] = %d\n", pipex->pipe_aux[READ]);
				dprintf(2, "EN EL HIJO: pipe_aux[WRITE] = %d\n", pipex->pipe_aux[WRITE]);				

				close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");

				pipex->pipe_father[READ] = pipex->pipe_aux[READ];

				pipex->flag = 0;
			}

		}
		pipex->index++;
	}
}


// printf("\nEl pid es %d\n\n", pipex->pid);
		// printf("EL flag es %d\n", pipex->flag);

		// if (pipex->flag == 1)
		// {
		// 	dprintf(2, "Esperando al hijo\n");

		// 	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	
		// 	pipex->pipe_father[READ] = pipex->pipe_aux[READ];

		// 	pipex->flag = 0;
		// }