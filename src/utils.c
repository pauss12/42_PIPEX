/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:50 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/29 19:50:52 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_error(char *error_message, char *cmd)
{
	char	*str;

	if (cmd == NULL)
		return ;
	str = ft_strjoin(error_message, cmd);
	ft_putendl_fd(str, 2);
	free(str);
}

void print_error_no_cmd(char *error_message, int code)
{
	ft_putendl_fd(error_message, 2);
	exit(code);
}

char	*search_path(t_pipex *pipex, char **cmd_splitted)
{
	char	*line;
	char	*path_slash;
	int		i;

	i = 0;
	if (pipex->path == NULL)
		return (NULL);
	while (pipex->path[i] != NULL)
	{
		path_slash = ft_strjoin(pipex->path[i], "/");
		line = ft_strjoin(path_slash, cmd_splitted[0]);
		free(path_slash);
		if (access(line, F_OK | X_OK) == 0)
		{
			return (line);
		}
		free(line);
		i++;
	}
	return (cmd_splitted[0]);
}

char	**get_path(char **envp)
{
	int		i;
	char	**str;

	i = 0;
	str = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			str = ft_split(envp[i] + 5, ':');
			if (!str)
				free_double_str(str);
			return (str);
		}
		i++;
	}
	return (NULL);
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
