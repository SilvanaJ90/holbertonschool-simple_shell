#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	ssize_t characterRead = 0;
	char **tokens, *line = NULL;
	char cmd[100], command[100], *parameters[20];
	char *envp[] ={(char *) "PATH=/usr/bin", 0};
	/*int codeExecute = 0;*/
	/*char *line = NULL;*/

	while (1)
	{
		_prompt();
		line = _getline(&characterRead);
		tokens = _strtok(line, characterRead);
		if (fork() != 0)
			wait (NULL);
		else
		{
			_strcpy (cmd, "/usr/bin");
			_strcat(cmd, command);
			execve(cmd, parameters, envp);
		}
		if (_strcmp (command, "exit") == 0 )
			break;
	}
}
