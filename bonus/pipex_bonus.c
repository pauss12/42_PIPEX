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

#include "../include/pipex_bonus.h"

void	close_pipes_and_free(t_pipex *pipex)
{
	if (pipex->path != NULL)
		free_double_str(pipex->path);
	if (pipex->pipe_father[0] != -1)
		close_fd(&pipex->pipe_father[0], "pipex->pipe_father[0]");
	if (pipex->pipe_father[1] != -1)
		close_fd(&pipex->pipe_father[1], "pipex->pipe_father[1]");
}

static void	initialize_here_doc(t_pipex *pipex, char **argv, int argc)
{
	pipex->begin_commands = 3;
	pipex->num_cmds = argc - 4;
	pipex->infile = "temp";
	pipex->outfile = argv[argc - 1];
}

void	treat_here_doc(t_pipex *pipex, char *argv[], int argc)
{
	char	*line;

	line = NULL;
	initialize_here_doc(pipex, argv, argc);
	pipex->fd[WRITE] = open(pipex->infile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (access(pipex->infile, W_OK) == -1)
		error_no_cmd(RED "Error\n" END "No write permissions temp\n", 1, pipex);
	else
		error_no_cmd(RED "Error\n" END "Error opening temp\n", 1, pipex);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& line[ft_strlen(argv[2]) + 1] == '\0')
		{
			free(line);
			break ;
		}
		write(pipex->fd[WRITE], line, ft_strlen(line));
		free(line);
	}
	close_fd(&pipex->fd[WRITE], "pipex->fd[WRITE]");
	command(pipex, argv, pipex->begin_commands);
}

void	treat_not_here_doc(t_pipex *pipex, char **argv, int argc)
{
	pipex->begin_commands = 2;
	pipex->num_cmds = argc - 3;
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	command(pipex, argv, pipex->begin_commands);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;
	int		status;

	status = 0;
	initialize_pipex(&pipex, envp);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		treat_here_doc(&pipex, argv, argc);
	else
		treat_not_here_doc(&pipex, argv, argc);
	close_pipes_and_free(&pipex);
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
