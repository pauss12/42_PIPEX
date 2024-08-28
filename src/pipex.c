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

void	end_process(t_pipex *pipex)
{
	if (pipex->path != NULL)
		free_double_str(pipex->path);
	if (pipex->pipe_fd[0] != -1)
		close_fd(&pipex->pipe_fd[0], "pipex->pipe_fd[0]");
	if (pipex->pipe_fd[1] != -1)
		close_fd(&pipex->pipe_fd[1], "pipex->pipe_fd[1]");
}

static void	initialize(t_pipex *pipex, char **envp)
{
	pipex->envp = envp;
	pipex->path = get_path(pipex->envp);
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->pid = -1;
	pipex->pid2 = -1;
}

void close_fd(int *fd, char *name)
{
	char *str;

	if (close(*fd) == -1)
	{
		str = ft_strjoin(RED "Error\n" END "Error closing ", name);
		printf("%s\n", str);
		ft_putendl_fd(str, 2);
		free(str);
	}
	else
		*fd = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (argc == 5)
	{
		initialize(&pipex, envp);
		if (pipe(pipex.pipe_fd) == -1)
			error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1, &pipex);
		pipex.pid = fork();
		if (pipex.pid == 0)
			first_command(&pipex, argv[2], argv[1]);
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
			second_command(&pipex, argv[3], argv[4]);
		end_process(&pipex);
		waitpid(pipex.pid, &status, 0);
		waitpid(pipex.pid2, &status, 0);
		if (WEXITSTATUS(status) == 127)
			exit(127);
	}
	else
		ft_putendl_fd(RED "Error\n" END "Number of arguments\n", 1);
	return (0);
}
