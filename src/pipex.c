/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:45 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/29 19:50:46 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	end_process(t_pipex pipex)
{
	if (close(pipex.pipe_fd[1]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[1]\n", 1);
	if (close(pipex.pipe_fd[0]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
}

static void	initialize(t_pipex *pipex)
{
	pipex->path = NULL;
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->pid = -1;
	pipex->pid2 = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (argc != 5)
		print_error_no_cmd(RED "Error\n" END "Wrong number of arguments\n", 1);
	initialize(&pipex);
	if (pipe(pipex.pipe_fd) == -1)
		print_error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
	pipex.pid = fork();
	if (pipex.pid == 0)
		first_command(pipex, argv[2], envp, argv[1]);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_command(pipex, argv[3], envp, argv[4]);
	end_process(pipex);
	waitpid(pipex.pid, &status, 0);
	waitpid(pipex.pid2, &status, 0);
	if (WEXITSTATUS(status) == 127)
		exit(127);
	return (0);
}
