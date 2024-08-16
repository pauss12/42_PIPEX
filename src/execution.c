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

void	first_command(t_pipex pipex, char *cmd, char **envp, char *file_name)
{
	pipex.fd[0] = open(file_name, O_RDONLY);
	if (pipex.fd[0] == -1)
	{
		end_process(pipex);
		print_error_no_cmd(RED "Error\n" END "Error opening files --\n", 1);
	}
	if (access(file_name, R_OK) == -1)
	{
		end_process(pipex);
		print_error_no_cmd(RED "Error\n" END "No read permissions for input file\n", 1);
	}
	if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);
	if (close(pipex.fd[0]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing fd[0]\n", 1);
	if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO\n", 1);
	if (close(pipex.pipe_fd[1]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[1]\n", 1);
	if (close(pipex.pipe_fd[0]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
	execute(pipex, cmd, envp);
}

void	second_command(t_pipex pipex, char *cmd, char **envp, char *file_name)
{
	pipex.fd[1] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex.fd[1] == -1)
		print_error_no_cmd(RED "Error\n" END "Error opening files\n", 1);
	if (access(file_name, W_OK) == -1)
		ft_putstr_fd(RED "Error\n" END "No write permissions for output file --\n", 1);
	if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);
	
	if (close(pipex.pipe_fd[0]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
	
	if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
		print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO\n", 1);
	
	if (close(pipex.fd[1]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing fd[1]\n", 1);
	
	if (close(pipex.pipe_fd[1]) == -1)
		print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[1]\n", 1);
	execute(pipex, cmd, envp);
}

void	check_if_accesible(char **str, t_pipex pipex, char *cmd, char **envp)
{
	char	*temp;

	temp = NULL;
	if (*str == NULL)
	{
		free_double_str(str);
		print_error("command not found: ", cmd);
		exit(127);
	}
	pipex.path = get_path(envp);
	if ((access(str[0], F_OK | X_OK) == 0) && ft_strnstr(str[0], "./", 2))
	{
		if (execve(str[0], str, envp) == -1)
		{
			print_error("command not found: ", str[0]);
			free_double_str(str);
			free(cmd);
			free_double_str(pipex.path);
			exit(127);
		}
	}
	else if ((access(str[0], F_OK | X_OK) != 0) && ft_strchr(str[0], '/'))
	{
		print_error("command not found: ", str[0]);
		free(cmd);
		free_double_str(str);
		free_double_str(pipex.path);
		exit(127);
	}
	else
	{
		temp = search_path(&pipex, str);
		if (temp == NULL || execve(temp, str, envp) == -1)
		{
			print_error("command not found: ", cmd);
			free_double_str(str);
			free_double_str(pipex.path);
			exit(127);
		}
		free(cmd);
		free_double_str(str);
		free(temp);
	}
	free_double_str(pipex.path);
}

void	execute(t_pipex pipex, char *command_argv, char **envp)
{
	char	**str;

	str = ft_split(command_argv, ' ');
	if (str == NULL)
	{
		free_double_str(str);
		print_error_no_cmd(RED "Error\n" END "Split failed\n", 1);
	}
	check_if_accesible(str, pipex, command_argv, envp);
}
