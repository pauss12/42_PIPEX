/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:22:41 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/30 13:22:43 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_command(t_pipex *pipex, char *cmd, char *file_name)
{
	pipex->fd[READ] = open(file_name, O_RDONLY);
	if (pipex->fd[READ] == -1)
	{
		if (access(file_name, F_OK) == -1)
			error_no_cmd(RED "Error\n" END "File not found\n", 1, pipex);
		else if (access(file_name, W_OK) == -1)
			error_no_cmd(RED "Error\n" END "No write permissions\n", 1, pipex);
		else
			error_no_cmd(RED "Error\n" END "Error opening input\n", 1, pipex);
	}
	if (dup2(pipex->fd[READ], STDIN_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1, pipex);
	close_fd(&pipex->fd[READ], "pipex->fd[READ]");
	if (dup2(pipex->pipe_fd[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1, pipex);
	close_fd(&pipex->pipe_fd[WRITE], "pipex->pipe_fd[WRITE]");
	close_fd(&pipex->pipe_fd[READ], "pipex->pipe_fd[READ]");
	execute(pipex, cmd);
}

void	second_command(t_pipex *pipex, char *cmd, char *file_name)
{
	pipex->fd[WRITE] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->fd[WRITE] == -1)
	{
		if (access(file_name, F_OK) == -1)
			error_no_cmd(RED "Error\n" END "File not found\n", 1, pipex);
		else if (access(file_name, W_OK) == -1)
			error_no_cmd(RED "Error\n" END "No write permissions\n", 1, pipex);
		else
			error_no_cmd(RED "Error\n" END "Error opening output\n", 1, pipex);
	}
	if (dup2(pipex->fd[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1, pipex);
	close_fd(&pipex->fd[WRITE], "pipex->fd[WRITE]");
	if (dup2(pipex->pipe_fd[READ], STDIN_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1, pipex);
	close_fd(&pipex->pipe_fd[READ], "pipex->pipe_fd[READ]");
	close_fd(&pipex->pipe_fd[WRITE], "pipex->pipe_fd[WRITE]");
	execute(pipex, cmd);
}

static void	free_strings(char **str, char **path, char *cmd)
{
	print_error("command not found: ", cmd);
	if (str != NULL)
		free_double_str(str);
	if (path != NULL)
		free_double_str(path);
	exit(127);
}

void	check_if_accesible(char **str, t_pipex *pipex, char *cmd)
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
	else if ((access(str[0], F_OK | X_OK) == 0) && ft_strchr(str[0], '/'))
	{
		if (execve(str[0], str, pipex->envp) == -1)
			free_strings(str, pipex->path, str[0]);
	}
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
	{
		free_double_str(str);
		error_no_cmd(RED "Error\n" END "Split failed\n", 1, pipex);
	}
	check_if_accesible(str, pipex, command_argv);
}
