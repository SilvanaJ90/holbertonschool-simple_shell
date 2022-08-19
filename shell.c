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
	int status = 0;
	char *prompt = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, getStringLen(prompt));
		line = _getline(&characterRead);
		if (characterRead == -1)
			exit(EXIT_FAILURE);
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(WEXITSTATUS(status));
		}
		tokens = _strtok(line, characterRead);
		if (tokens[0] != NULL)
			status = _execute(tokens, status);
		free(tokens);
	}
	return (WEXITSTATUS(status));
}
