#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _execute - check code
 * @tokens: value matriz pointer
 * Return: always 0
 */

int _execute(char **tokens, int status)
{
	pid_t cPid;
	char *command = NULL, **envp = NULL;
	envp = environ;
	/*comprueba si el comando es un comando integrado*/
	_builtin(tokens);
	/*_builtin(args);*/
	/*comprueba si existe el comando y genera las rutas para el comand */
	command = _pathSh(tokens[0]);
	if (command == NULL)
		return (EXIT_FAILURE);

	cPid = fork(); /*crea un nuevo proceso hijo */

	if (cPid == 0)
	{
		execve(command, tokens, envp);
	}
	else if (cPid > 0)
	{
		do {
			waitpid(cPid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
		perror("shell");
	return (status);
}
