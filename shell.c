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

int main (void)
{
	ssize_t characterRead = 0;
	char **tokens, *line = NULL;
	/*int codeExecute = 0;*/
	/*char *line = NULL;*/

	while (1)
	{
		_prompt();
		line = _getline(&characterRead);
		tokens = _strtok(line, characterRead);
		write(STDOUT_FILENO,  "$", **tokens);
		/*if (tokens[0] == NULL)
			codeExecute = _execute(tokens);*/
	}
}
