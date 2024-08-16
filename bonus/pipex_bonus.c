
#include <stdio.h>
#include <unistd.h>

#include "../include/pipex_bonus.h"

void close_all_fds(t_pipex *pipex)
{
	printf("Entra en close_all_fds --\n");

	//Comprobar si el fichero de entrada esta cerrado
	if (pipex->fd[0] != -1)
		close_fd(&pipex->fd[0], "pipex->fd[0]");

	//Comprobar si el pipe del padre esta cerrado
	if (pipex->pipe_father[0] != -1)
		close_fd(&pipex->pipe_father[0], "pipex->pipe_father[0]");

	//Comprobar si el pipe del padre esta cerrado
	if (pipex->pipe_father[1] != -1)
		close_fd(&pipex->pipe_father[1], "pipex->pipe_father[1]");

	//Comprobar si el fichero de salida esta cerrado
	if (pipex->fd[1] != -1)
		close_fd(&pipex->fd[1], "pipex->fd[1]");
}

int main(int argc, char *argv[], char **envp)
{
    t_pipex pipex;
	int status;

	status = 0;
    initialize_pipex(&pipex, envp, argc);
    command(&pipex, argv, argc);
	if (WEXITSTATUS(status) == 127)
		exit(127);
	close_all_fds(&pipex);
	return (0);
}