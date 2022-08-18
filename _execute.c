#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _execute(char **args)
{
	pid_t cPid;
	char *command = NULL, **envp = NULL;

	envp = environ;
	/*comprueba si el comando es un comando integrado*/
	if (_builtin(args) == EXIT_SUCCESS)
		return (EXIT_FAILURE);
	/*_builtin(args);*/
	/*comprueba si existe el comando y genera las rutas para el comand */
	command = _path(args[0]);
	if (command == NULL)
		return (EXIT_FAILURE);
	cPid = fork(); /*crea un nuevo proceso hijo */
	if (cPid == 0)
	{
		execve(args[0], args, envp);
		exit(EXIT_SUCCESS);
	}
	else if (cPid > 0)
	{
		int status;

		do {
			waitpid(cPid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("shell");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
