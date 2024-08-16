
/*void process_duplicates(t_pipex *pipex, char *command_argv)
{

	if (pipe(pipex->pipe_fd[pipex->index]) == -1)
	{
		print_error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
		exit(1);
	}

	// printf de los ficheros que esten abiertos
	printf("Fichero de entrada: %d\n", pipex->fd[0]);
	printf("Fichero de salida: %d\n", pipex->fd[1]);
	printf("Pipe de entrada: %d\n", pipex->pipe_fd[pipex->index][0]);
	printf("Pipe de salida: %d\n", pipex->pipe_fd[pipex->index][1]);
	printf("Index: %d\n", pipex->index);

	printf("\n\n");
	if (pipex->index == 0)
	{
		if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
			print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);

		if (dup2(pipex->pipe_fd[0][1], STDOUT_FILENO) == -1)
			print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO\n", 1);
		if (close(pipex->pipe_fd[0][0]) == -1)
			print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
		if (close(pipex->pipe_fd[0][1]) == -1)
			print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
	}
	else if (pipex->index == pipex->num_cmds - 1)
	{
		if (pipe(pipex->pipe_fd[1]) == -1)
		{
			print_error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
			exit(1);
		}
		printf("Pipe de entrada: %d\n", pipex->pipe_fd[pipex->index - 1][0]);
		printf("Pipe de salida: %d\n", pipex->pipe_fd[pipex->index][1]);
		if (dup2(pipex->pipe_fd[1][0], STDIN_FILENO) == -1)
			print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);
		if (dup2(pipex->pipe_fd[1][0], STDOUT_FILENO) == -1)
			print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO --\n", 1);
		if (close(pipex->pipe_fd[pipex->index][1]) == -1)
			print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[1]\n", 1);
		if (close(pipex->pipe_fd[pipex->index - 1][0]) == -1)
			print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
	}
	else
	{
		if (dup2(pipex->pipe_fd[pipex->index - 1][0], STDIN_FILENO) == -1)
			print_error_no_cmd(RED "Error\n" END "dup2 failed in STDIN_FILENO\n", 1);
		if (dup2(pipex->pipe_fd[pipex->index][1], STDOUT_FILENO) == -1)
			print_error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT_FILENO\n", 1);
		if (close(pipex->pipe_fd[pipex->index][0]) == -1)
			print_error_no_cmd(RED "Error\n" END "Error closing pipe_fd[0]\n", 1);
	}
	execute(pipex, command_argv);
}

void command(t_pipex *pipex, char **argv)
{
	if (pipe(pipex->pipe_fd[0]) == -1)
	{
		print_error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1);
		exit(1);
	}
	while (pipex->index < pipex->num_cmds)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
			print_error_no_cmd(RED "Error\n" END "Error creating child process\n", 1);
		else if (pipex->pid == 0)
			process_duplicates(pipex, argv[2 + pipex->index]);
		else
		{
			printf("Entra aquui, INDEX %d\n", pipex->index);
			pipex->index++;
			close_all_fds(pipex);
		}
	}
}*/