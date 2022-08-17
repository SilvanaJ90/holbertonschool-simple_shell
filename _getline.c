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

char * _getline(ssize_t *characterRead)
{
	char *line = NULL;
	size_t lineSize = 0;

	*characterRead = getline(&line, &lineSize, stdin);
	return (line);
}
