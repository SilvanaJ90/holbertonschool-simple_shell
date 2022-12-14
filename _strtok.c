#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * _strtok - check code
 * @line: value buffer
 * @characterRead: size buffer
 * Return: always 0
 */

char **_strtok(char *line, ssize_t characterRead)
{
	char *copy_line = NULL, *token, **argv;
	char *delim = " \n";
	int i = 0, characterToken = 0;

	/*copy buffer - assign space for it*/
	copy_line = malloc(sizeof(char) * characterRead);
	strcpy(copy_line, line);
	/*count token*/
	token = strtok(line, delim);
	while (token != NULL)
	{
		characterToken++;
		token = strtok(NULL, delim);
	}
	characterToken++;
	/*assig space for token we count on while */
	argv = malloc(sizeof(char *) * characterToken);
	token = strtok(copy_line, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(copy_line);
	i = 0;
	return (argv);
}
