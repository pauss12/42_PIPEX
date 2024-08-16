
PIPEX CON UN SOLO COMANDO

void	first_command(t_pipex pipex, char *command_argv, char **envp)
{
	if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
		print_error("dup2 failed in STDIN_FILENO", NULL, -1);
	close(pipex.fd[0]);
	if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 failed in STDOUT_FILENO", NULL, -1);
	close(pipex.pipe_fd[1]);
	close(pipex.pipe_fd[0]);
	close(pipex.fd[1]);
	execute(pipex, command_argv, envp);
}

void	execute(t_pipex pipex, char *command_argv, char **envp)
{
	char *cmd;
	char **cmd_splitted;

	cmd = NULL;
	pipex.path = get_path(envp);
	cmd_splitted = ft_split(command_argv, ' ');
	if (cmd_splitted == NULL)
		print_error("ft_split failed", NULL, 1);
	if (access(cmd_splitted[0], F_OK | X_OK) == 0)
	{
		//Cual es la ruta que usa?
		ft_printf("cmd_splitted[0]: %s\n", cmd_splitted[0]);

		//Creo que hace la comprobacion en "/bin/cat", si uso el comando "cat"
		if (execve(cmd_splitted[0], cmd_splitted, envp) == -1)
		{
			free_double_str(cmd_splitted);
			print_error("command not found: ", command_argv, 127);
		}
	}
	else
	{
		cmd = search_path(&pipex, cmd_splitted);
		if (cmd == NULL || execve(cmd, cmd_splitted, envp) == -1)
		{
			free_double_str(cmd_splitted);
			print_error("command not found: ", command_argv, 127);
		}
		free_double_str(cmd_splitted);
		free(cmd);
	}
}

char	*search_path(t_pipex *pipex, char **cmd_splitted)
{
	char	*line;
	char	*path_slash;
	int		i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		path_slash = ft_strjoin(pipex->path[i], "/");
		line = ft_strjoin(path_slash, cmd_splitted[0]);
		free(path_slash);
		//Encontrar el path en el que se puede ejecutar y devolverla
		if (access(line, F_OK | X_OK) == 0)
		{
			return (line);
		}
		free(line);
		i++;
	}
	return (NULL);
}

int main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;
	int 	status;

	(void)argc;
	/*
		if (argc != 5)
		{
			ft_putstr_fd(RED"Error\n" END "Wrong number of arguments\n", 2);
			return (1);
		}
	*/
	pipex.fd[0] = open(argv[1], O_RDONLY);
	pipex.fd[1] = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (pipe(pipex.pipe_fd) == -1)
	{
		ft_putstr_fd(RED"Error\n" END "Pipe failed\n", 2);
		return (1);
	}
	// printf("pid ANTES de hacer el fork: %d\n\n\n", getpid());
	pipex.pid = fork();
	printf("pid despues de hacer el fork: %d\n\n", pipex.pid);
	if (pipex.pid == 0)
	{
		// Estas en el hijo, es un identificador.
		dprintf(2, "-- getpid() es: %d y el PID  es: %d\n", getpid(), pipex.pid);
		first_command(pipex, argv[2], envp);
	}
	else
	{
		// Estas en el padre, es un identificador.
		dprintf(2, "getpid() es: %d y el PID  es: %d\n", getpid(), pipex.pid);
	}
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(pipex.pid, &status, 0);
	if (WEXITSTATUS(status) == 127)
		exit(127);
	return (0);
}

/*void	execute(t_pipex pipex, char *command_argv, char **envp)
{
	char	*cmd;
	char	**cmd_splitted;

	cmd = NULL;
	cmd_splitted = NULL;
	pipex.path = get_path(envp);
	if (pipex.path == NULL)
		print_error("PATH not found", NULL, 1);
	cmd_splitted = ft_split(command_argv, ' ');
	if (cmd_splitted == NULL)
		print_error("ft_split failed", NULL, 1);
	if (access(cmd_splitted[0], F_OK | X_OK) == 0)
	{
		ft_printf("cmd_splitted[0]: %s\n", cmd_splitted[0]);
		if (execve(cmd_splitted[0], cmd_splitted, envp) == -1)
		{
			free_double_str(cmd_splitted);
			print_error("command not found: ", command_argv, 127);
		}
	}
	else
	{
		cmd = search_path(&pipex, cmd_splitted);
		if (cmd == NULL || execve(cmd, cmd_splitted, envp) == -1)
		{
			free_double_str(cmd_splitted);
			print_error("command not found: ", command_argv, 127);
		}
		free_double_str(cmd_splitted);
		free(cmd);
	}
}*/
