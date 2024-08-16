/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 03:29:02 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 03:29:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

//< infile cmd1 | cmd  > outfile
// ./prorgrama infile cmd1 cmd2 outfile

// pipe{[2]  == [0 READ] [1 WRITE]}
// excve(cmd1, cmd1, NULL) == cat sleep 

//infile | cat | outfile


static void	pid1(int *fd, int *pipe_fd)
{
	char *cmd[] = {"sleep", " 5", (void *)0};
	printf("pid1\n");
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(fd[1]);
	execvp(cmd[0], cmd);
	exit(0);
}



static void	pid22(int *fd, int *pipe_fd)
{
	char *cmd[] = {"ls", NULL, (void *)0};

	printf("pid2\n");
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(pipe_fd[1]);
	execvp(cmd[0], cmd);
	exit(0);
}

int	main(void)
{
	int	fd[2];
	int	pipe_fd[2];
	pid_t	pid;
	pid_t	pid2;
	int		status;

	fd[0] = open("input.txt", O_RDONLY);
	fd[1] = open("output.txt", O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (pipe(pipe_fd) < 0)
		printf("Error creating pipe\n");
	pid = fork();
	if (pid == 0)
	{
		pid1(fd, pipe_fd);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		pid22(fd, pipe_fd);
	}
	//status = (void *)0;
	printf("padre\n");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (waitpid(pid, &status, 0) > 0)
		waitpid(pid2, &status, 0);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
