#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - check code
 * Return: always 0
 */

int getStringLen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main (void)
{
	char *prompt = "$ ", *line = NULL, *copy_line = NULL, *token;
	char *delim = " \n", **text;
	size_t lineSize = 0;
	int characterRead = 0, characterToken = 0, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, getStringLen(prompt));
		characterRead = getline(&line, &lineSize, stdin);
		write(STDOUT_FILENO, line, characterRead);
		if (characterRead == -1)
			return (-1);
		if (!isatty(STDIN_FILENO))
			break;
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
		text = malloc(sizeof(char *) * characterToken);
		token = strtok(copy_line, delim);
		while (token != NULL)
		{
			text[i] = malloc(sizeof(char) * strlen(token));
			strcpy(text[i], token);
			i++;
			token = strtok(NULL, delim);
		}
		text[i] = NULL;
		i = 0;
		/*if(!pid)
		{*/
		if (execve(argv[0], text, NULL) == -1)
				perror("Error:");
			/*else
			{
				wait();
				}*/
	}
	return (EXIT_SUCCESS);
}
