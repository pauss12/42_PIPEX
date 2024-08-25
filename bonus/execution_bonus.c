/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:22:41 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/30 13:22:43 by pmendez-         ###   ########.fr       */
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


/*
	dprintf(2, "EL comadno entra aqui y utiliza el comando [%s]\n", argv[argc - 1 - pipex->index]);

	dprintf(2, "\npipe_father[READ] es %d\n", pipex->pipe_father[READ]);
	dprintf(2, "pipe_father[WRITE] es %d\n\n", pipex->pipe_father[WRITE]);

	if (pipe(pipex->pipe_aux) == -1)
		error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);

	dprintf(2, "El pipe aux[READ] es %d\n", pipex->pipe_aux[READ]);
	dprintf(2, "El pipe aux[WRITE] es %d\n\n", pipex->pipe_aux[WRITE]);
		
	if (dup2(pipex->pipe_father[READ], STDIN_FILENO) == -1)
	{
		close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");
		close_fd(&pipex->pipe_aux[READ], "pipe_aux[READ]");
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1);
	}

	//dprintf(2, "dup2 en -------------------\n");

	close_fd(&pipex->pipe_father[READ], "pipex->pipe_father[READ]");
	close_fd(&pipex->pipe_father[WRITE], "pipex->pipe_father[WRITE]");

	//dprintf(2, "despuees de cerrar los pipes\n");

	if (dup2(pipex->pipe_aux[WRITE], STDOUT_FILENO) == -1)
	{
		close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");
		close_fd(&pipex->pipe_aux[READ], "pipe_aux[READ]");
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1);
	}

	//dprintf(2, "2   dup2 en -------------------\n");
	close_fd(&pipex->pipe_aux[WRITE], "pipe_aux[WRITE]");


	//dprintf(2, "2 despuees de cerrar los pipes\n");

	//dprintf(2, "REDIRECCIONAR A %s\n", argv[argc - 1 - pipex->index]);


	dprintf(2, "pipe_father[READ] = %d\n", pipex->pipe_father[READ]);
	execute(pipex, argv[argc - 1 - pipex->index]);

*/