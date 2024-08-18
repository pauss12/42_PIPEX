/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_memory_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:07:16 by pmendez-          #+#    #+#             */
/*   Updated: 2024/08/05 16:07:18 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	initialize_pipex(t_pipex *pipex, char **envp, int argc)
{
	pipex->envp = envp;
	pipex->path = get_path(pipex->envp);
	pipex->index = 0;
	pipex->pid = 0;
	pipex->num_cmds = 0;
	pipex->num_cmds = argc - 3;
	pipex->pipe_father[0] = -1;
	pipex->pipe_father[1] = -1;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
}

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}
