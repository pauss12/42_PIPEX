/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:51:48 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/29 19:51:59 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

# include "../libft/libft.h"

# define RED "\033[0;31m"
# define END "\033[0m"

typedef struct s_pipex
{
	char	**path;
	char	**envp;
	int		pipe_father[2];
	int		fd[2];
	pid_t	pid;
	int		index;
	int		num_cmds;
}	t_pipex;

//pipex.c
void	close_pipes(t_pipex *pipex);

// reserve_and_destroy_memory.c
void	initialize_pipex(t_pipex *pipex, char **envp, int argc);
void	free_double_str(char **str);

// utils_bonus.c
void	print_error(char *error_message, char *cmd);
void	print_error_no_cmd(char *error_message, int code);
char	*search_path(t_pipex *pipex, char **cmd_splitted);
char	**get_path(char **envp);
void	close_fd(int *fd, char *name);

// execution_bonus.c
void	process_duplicates(t_pipex *pipex, char *argv[], int argc);
void	command(t_pipex *pipex, char **argv, int argc);
void	check_if_accesible(t_pipex *pipex, char **str, char *cmd);
void	execute(t_pipex *pipex, char *command_argv);

#endif
