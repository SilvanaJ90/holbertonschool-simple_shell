#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*#include "main.h"*/

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

char _prompt()
{
	char *prompt = "$ ";
	/*write conventional output fot the user to see*/
	write(STDOUT_FILENO, prompt, getStringLen(prompt));
	return (EXIT_SUCCESS);
}
