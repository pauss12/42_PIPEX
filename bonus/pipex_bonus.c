
#include <stdio.h>
#include <unistd.h>

#include "../include/pipex_bonus.h"

void close_all_fds(t_pipex *pipex)
{
	if (pipex->pipe_father[0] != -1)
		close_fd(&pipex->pipe_father[0], "pipex->pipe_father[0]");

	if (pipex->pipe_father[1] != -1)
		close_fd(&pipex->pipe_father[1], "pipex->pipe_father[1]");
}

int main(int argc, char *argv[], char **envp)
{
    t_pipex pipex;
	int status;

	status = 0;
    initialize_pipex(&pipex, envp, argc);
    command(&pipex, argv, argc);
	close_all_fds(&pipex);
	if (WEXITSTATUS(status) == 127)
		exit(127);
	return (0);
}