#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/*#include "main.h"*/

/**
 * getStringLen - check code
 * @str: pointer buffer - string
 * Return: always i
 */

int getStringLen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _prompt - check list
 * Return: always 0
 */

char _prompt(void)
{
	char *prompt = "$ ";
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, getStringLen(prompt));
	return (EXIT_SUCCESS);
}
