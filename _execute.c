#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _execute - check code
 * @tokens: value matriz pointer
 * @status: value status
 * Return: always 0
 */

int _execute(char **tokens, int status)
{
	pid_t cPid;
	char *command = NULL;

	/*comprueba si el comando es un comando integrado*/
	if (_builtin(tokens) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	/*_builtin(args);*/
	/*comprueba si existe el comando y genera las rutas para el comand */
	command = _pathSh(tokens[0]);
	if (!command)
		return (EXIT_FAILURE);

	cPid = fork(); /*crea un nuevo proceso hijo */

	if (cPid == 0)
	{
		execve(command, tokens, environ);
		exit(EXIT_SUCCESS);
	}
	else if (cPid > 0)
	{
		do {
			waitpid(cPid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (_strcmp(command, tokens[0]))
			free(command);
	}
	return (status);
}
