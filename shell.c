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
	int codeExecute = 0;

	while (1)
	{
		_prompt();
		line = _getline(&characterRead);
		if (characterRead == -1)
			exit(EXIT_FAILURE);
		tokens = _strtok(line, characterRead);
		if (tokens[0] != NULL)
			codeExecute = _execute(tokens);
		free(tokens);
		free(line);
	}
	return (codeExecute);
}
