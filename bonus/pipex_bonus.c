/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:45 by pmendez-          #+#    #+#             */
/*   Updated: 2024/08/25 23:30:45 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../include/pipex_bonus.h"

void	close_pipes(t_pipex *pipex)
{
	if (pipex->pipe_father[0] != -1)
		close_fd(&pipex->pipe_father[0], "pipex->pipe_father[0]");
	if (pipex->pipe_father[1] != -1)
		close_fd(&pipex->pipe_father[1], "pipex->pipe_father[1]");
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;
	int		status;

	status = 0;
	initialize_pipex(&pipex, envp, argc);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		printf("tiene here_doc\n");
	}
	else
		command(&pipex, argv, argc);
	close_pipes(&pipex);
	while (pipex.index >= 0)
	{
		waitpid(-1, &status, 0);
		pipex.index--;
		if (WEXITSTATUS(status) != 0 && WEXITSTATUS(status) != 127)
			exit(0);
	}
	if (WEXITSTATUS(status) == 127)
		exit(127);
	return (0);
}
