#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int getStringLen(char *str);
char _prompt(void);
char *_getline(ssize_t *characterRead);
char **_strtok(char *line, ssize_t characterRead);
int _execute(char **tokens);


/*global value*/
extern char **environ;

/**
 * struct builtin - simple shell
 * @name: value
 * @func: value
 *
 * Description: simple shell
 */

typedef struct builtin
{
	char *name;
	void (*func)(char **args);
}builtin;

 /* Funtions */

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/*Builtin */
char *_path(char *command);
int _builtin(char **args);
void _eexit(char **args);
void _cd(char **args);
void _help(char **args);
void _env(char **args);

#endif /* MAIN_H */
