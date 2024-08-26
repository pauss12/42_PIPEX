/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_memory_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:07:16 by pmendez-          #+#    #+#             */
/*   Updated: 2024/08/25 23:31:08 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	initialize_pipex(t_pipex *pipex, char **envp)
{
	pipex->envp = envp;
	pipex->path = get_path(pipex->envp);
	pipex->index = 0;
	pipex->pid = -1;
	pipex->num_cmds = 0;
	pipex->pipe_father[0] = -1;
	pipex->pipe_father[1] = -1;
	pipex->pipe_aux[0] = -1;
	pipex->pipe_aux[1] = -1;
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
	free(str);
}

void free_all(t_pipex *pipex, int argc)
{
	if (pipex->infile != NULL && pipex->num_cmds == argc - 4)
		free(pipex->infile);
	if (pipex->path != NULL)
		free_double_str(pipex->path);
}