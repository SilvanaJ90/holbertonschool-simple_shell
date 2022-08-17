#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _execute(char **tokens)
{
	pid_t cPid;
	char *command, **envp;
	envp = environ;
	/*comprueba si el comando es un comando integrado*/
	_builtin(tokens);
	/*comprueba si existe el comando y genera las rutas para el comand */
	command = _path(tokens[0]);
	if (command == NULL)
		return (EXIT_FAILURE);
	cPid = fork(); /*crea un nuevo proceso hijo */
	if (cPid == 0)
	{
		execve(command, tokens, envp);
		perror(tokens[0]);
		return (EXIT_SUCCESS);
	}
	else if (cPid > 0)	{
		int status;
		do{
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
