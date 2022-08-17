#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * main - check code
 * Return: always 0
 */

char _strtok()
{
	char *line = NULL;
	char *copy_line = NULL, **tokens;
	char *token, *delim = " \n";
	int characterToken = 0, i = 0, *characterRead = 0;

	/*copy buffer - assign space for it*/
	copy_line = malloc(sizeof(char) * *characterRead);
	_strcpy(copy_line, line);
	/*count token*/
	token = strtok(line, delim);
	while (token != NULL)
	{
		characterToken++;
		token = strtok(NULL, delim);
	}
	characterToken++;
	/*assig space for token we count on while */
	tokens = malloc(sizeof(char *) * characterToken);
	token = strtok(copy_line, delim);
	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (**tokens);
}
