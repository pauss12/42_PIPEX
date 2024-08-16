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

static void first_iteration(t_pipex *pipex, char *argv[])
{
	dprintf(2, "1. Entra en first iteration\n");

	pipex->fd[0] = open(argv[1], O_RDONLY);
	
	if (pipex->fd[0] == -1)
		print_error_no_cmd(RED "Error\n" END "Error opening files\n", 1);

	dprintf(2, "1. Despues de open\n\n");
	
	if (access(argv[1], R_OK) == -1)
		print_error_no_cmd(RED "Error\n" END "No read permissions for input file\n", 1);

	dprintf(2, "1. Despues de access\n\n");

	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);

	dprintf(2, "1. Despues de dup2\n\n");

	close_fd(&pipex->fd[0], "pipex->fd[0]");

	dprintf(2, "1. Despues de close fd[0]\n\n");

	if (dup2(pipex->pipe_father[1], STDOUT_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO\n", 1);

	dprintf(2, "1. Despues de dup2 pipe_father[1]\n\n");

	close_fd(&pipex->pipe_father[1], "pipex->pipe_father[1]");

	dprintf(2, "1. despues de close pipe_father[1]\n");

	close_fd(&pipex->pipe_father[0], "pipex->pipe_father[0]");

	dprintf(2, "1. Antes de execute ... 1 \n");

	execute(pipex, argv[2]);

	dprintf(2, "1. Sale de first iteration\n");
}

static void last_iteration(t_pipex *pipex, char *argv[], int argc)
{
	pipex->fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	
	if (pipex->fd[1] == -1)
		print_error_no_cmd(RED "Error\n" END "Error opening files\n", 1);
	
	if (access(argv[argc - 1], W_OK) == -1)
		ft_putstr_fd(RED "Error\n" END "No write permissions for output file\n", 1);

	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO\n", 1);

	
	close_fd(&pipex->fd[1], "pipex->fd[1]");
	
	if (dup2(pipex->pipe_father[0], STDIN_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);
	
	close_fd(&pipex->pipe_father[0], "pipex->pipe_father[0]");

	close_fd(&pipex->pipe_father[1], "pipex->pipe_father[1]");

	dprintf(2, "Antes de execute ... 2 \n");

	execute(pipex, argv[argc - 2]);

	dprintf(2, "Sale de last iteration\n");
}

void process_duplicates(t_pipex *pipex, char *argv[], int argc)
{
	// cmd = argv[2 + pipex->index]

	if (pipex->index == 0)
		first_iteration(pipex, argv);
	else if (pipex->index == pipex->num_cmds - 1)
	{
		printf("Entra en el ultimo proceso\n\n");
		last_iteration(pipex, argv, argc);
	}

	dprintf(2, "Sale de process duplicates	\n");
}

void command(t_pipex *pipex, char **argv, int argc)
{
	printf("El numero de comandos es: %d\n\n", pipex->num_cmds);
	/*printf("El numero de index es %d\n", pipex->index);*/

	if (pipe(pipex->pipe_father) == -1)
	{
		print_error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
		exit(1);
	}
	while (pipex->index < 1)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
			print_error_no_cmd(RED "Error\n" END "Error creating child process\n", 1);
		else if (pipex->pid == 0)
			process_duplicates(pipex, argv, argc);
		else
		{
			printf("Entra aqui, INDEX %d\n", pipex->index);
			pipex->index++;
			waitpid(pipex->pid, NULL, 0);
			//close_all_fds(pipex);
		}
	}
}
