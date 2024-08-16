
#include <stdio.h>
#include <unistd.h>

#include "../include/pipex_bonus.h"

int main(int argc, char *argv[], char **envp)
{
    t_pipex pipex;
	int status;

	status = 0;
    initialize_pipex(&pipex, envp, argc);
    command(&pipex, argv, argc);
	if (WEXITSTATUS(status) == 127)
		exit(127);
	//close_all_fds(&pipex);
	free_all(&pipex);
	return (0);
}