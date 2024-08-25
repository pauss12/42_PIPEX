/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:22:41 by pmendez-          #+#    #+#             */
/*   Updated: 2024/08/25 23:30:29 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	free_strings(char **str, char **path, char *cmd)
{
	print_error("command not found: ", cmd);
	if (str != NULL)
		free_double_str(str);
	if (path != NULL)
		free_double_str(path);
	exit(127);
}

void	check_if_accesible(t_pipex *pipex, char **str, char *cmd)
{
	char	*temp;

	temp = NULL;
	if (*str == NULL)
		free_strings(str, pipex->path, cmd);
	if ((access(str[0], F_OK | X_OK) == 0) && ft_strnstr(str[0], "./", 2))
	{
		if (execve(str[0], str, pipex->envp) == -1)
			free_strings(str, pipex->path, str[0]);
	}
	else if ((access(str[0], F_OK | X_OK) != 0) && ft_strchr(str[0], '/'))
		free_strings(str, pipex->path, str[0]);
	else
	{
		temp = search_path(pipex, str);
		if (temp == NULL || execve(temp, str, pipex->envp) == -1)
			free_strings(str, pipex->path, cmd);
	}
}

void	execute(t_pipex *pipex, char *command_argv)
{
	char	**str;

	str = ft_split(command_argv, ' ');
	if (str == NULL)
		error_no_cmd(RED "Error\n" END "Split failed\n", 1);
	check_if_accesible(pipex, str, command_argv);
}
