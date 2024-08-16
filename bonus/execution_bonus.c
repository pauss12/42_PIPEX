
#include "../include/pipex_bonus.h"

void check_if_accesible(t_pipex *pipex, char **str, char *cmd)
{
	char	*temp;

	temp = NULL;
	if (*str == NULL)
	{
		free_double_str(str);
		print_error("command not found: ", cmd);
		exit(127);
	}

	if ((access(str[0], F_OK | X_OK) == 0) && ft_strnstr(str[0], "./", 2))
	{
		dprintf(2, "\n\nEntra en el if del access! El del [./]\n");
		if (execve(str[0], str, pipex->envp) == -1)
		{
			print_error("command not found: ", str[0]);
			free_double_str(str);
			free(cmd);
			free_double_str(pipex->path);
			exit(127);
		}
	}
	else if ((access(str[0], F_OK | X_OK) != 0) && ft_strchr(str[0], '/'))
	{
		dprintf(2, "\n\nEntra en el else if del access! El del [/]\n");
		print_error("command not found: ", str[0]);
		free(cmd);
		free_double_str(str);
		free_double_str(pipex->path);
		exit(127);
	}
	else
	{
		int i;

		i = 0;
		dprintf(2, "\n\nEntra en el else del access! El del path\n\n");
		temp = search_path(pipex, str);

		for (i = 0; str[i] != NULL; i++) 
		{
			dprintf(2, "str[%d]: %s\n", i, str[i]);
		}

		if (str[i] == NULL)
			dprintf(2, "str[%d]: %s\n", i, str[i]);

		dprintf(2, "\n\nEl temp es: %s\n", temp);

		//Imprimir la variable de entorno
		/*for (i = 0; pipex->envp[i] != NULL; i++)
		{
			dprintf(2, "envp[%d]: %s\n", i, pipex->envp[i]);
		}*/

		//dprintf(2, "El intento de ejecucion es %d\n", execve(temp, str, pipex->envp));
		if (temp == NULL || execve(temp, str, pipex->envp) == -1)
		{
			print_error("--command not found: ", cmd);
			free_double_str(str);
			free_double_str(pipex->path);
			exit(127);
		}
	}
	free_double_str(str);
    free(cmd);
	free(temp);

	exit(127);
}

void execute(t_pipex *pipex, char *command_argv)
{
	char **str;

	str = ft_split(command_argv, ' ');
	if (str == NULL)
		print_error_no_cmd(RED "Error\n" END "Split failed\n", 1);
	dprintf(2, "\n\nEntra en execute; y command argv es: [%s] ademas de STR[0] es [%s]\n", command_argv, str[0]);
	check_if_accesible(pipex, str, command_argv);
}

	/*char *temp;

	temp = NULL;
	if (*str == NULL)
	{
		free_double_str(str);
		print_error("command not found: ", cmd);
		exit(127);
	}
	pipex->path = get_path(pipex->envp);

	dprintf(2, "str[0]: %s\n", cmd);

	// if (access(str[0], F_OK | X_OK) == 0)
	// {
	// 	if (execve(str[0], str, pipex->envp) == -1)
	// 	{
	// 		print_error("command not found: ", str[0]);
	// 		free_double_str(str);
	// 		exit(127);
	// 	}
	// }
	// else
	// {
	// 	temp = search_path(pipex, str);
	// 	if (temp == NULL || execve(temp, str, pipex->envp) == -1)
	// 	{
	// 		print_error("command not found: ", cmd);
	// 		free_double_str(str);
	// 		exit(127);
	// 	}
	// 	free_double_str(str);
	// 	free(temp);
	// }

	dprintf(2, "Antes de entrar en el if\n");

	if ((access(str[0], F_OK | X_OK) == 0) && ft_strnstr(str[0], "./", 2))
	{
		dprintf(2, "\n\nEntra en el if dek access\n");
		if (execve(str[0], str, pipex->envp) == -1)
		{
			print_error("command not found: ", str[0]);
			free_double_str(str);
			free(cmd);
			free_double_str(pipex->path);
			exit(127);
		}
	}
	else if ((access(str[0], F_OK | X_OK) != 0) && ft_strchr(str[0], '/'))
	{
		dprintf(2, "\nEntra en el else if dek access\n");
		print_error("command not found: ", str[0]);
		free(cmd);
		free_double_str(str);
		free_double_str(pipex->path);
		exit(127);
	}
	else
	{
		int i;

		i = 0;
		dprintf(2, "\nEntra en el else dek access\n");
		temp = search_path(pipex, str);
		dprintf(2, "\ntemp: %s\n", temp);

		dprintf(2, "\nstr[0]: %s\n", str[0]);
		dprintf(2, "str[1]: %s\n\nmake", str[1]);

		dprintf(2, "\nEl intento de ejecucion es %d\n", execve(temp, str, pipex->envp));
		if (temp == NULL || execve(temp, str, pipex->envp) == -1)
		{
			print_error("command not found: ", cmd);
			free_double_str(str);
			free_double_str(pipex->path);
			dprintf(2, "hace exit\n");
			exit(127);
		}
		dprintf(2, "\nsale del intento de ejecucion \n");
		free(cmd);
		free_double_str(str);
		free(temp);
		dprintf(2, "\nSale del else dek access\n");
	}

	dprintf(2, "\n\nSale de check_if_accesible\n");

	free_double_str(pipex->path);
	*/