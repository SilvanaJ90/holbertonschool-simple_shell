#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _getline - check code
 * @line: pointer buffer - string
 * @lineSize: size pointer buffer
 * Return: always 0
 */

int getStringLen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

ssize_t _getline()
{
	char *prompt = "$ ";
	char *line = NULL;
	size_t lineSize = 0;
	int characterRead = 0;
	/*write conventional output fot the user to see*/
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, getStringLen(prompt));
	/* read line */
	characterRead = getline(&line, &lineSize, stdin);
	write(STDOUT_FILENO, line, characterRead);
	return (EXIT_SUCCESS);
}
