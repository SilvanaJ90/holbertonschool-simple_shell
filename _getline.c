#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _getline - check code
 * @characterRead: value read _getline
 * Return: buffer
 */

char *_getline(ssize_t *characterRead)
{
	char *line = NULL;
	size_t lineSize = 0;

	*characterRead = getline(&line, &lineSize, stdin);
	write(STDOUT_FILENO, line, characterRead);
	return (line);
}
