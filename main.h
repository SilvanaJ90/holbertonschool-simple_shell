#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int getStringLen(char *str);
char _prompt();
char * _getline(ssize_t *characterRead);
char** _strtok(char *line, ssize_t characterRead);
int _execute(char **tokens);



/*global value*/
extern char **environ;



/*typedef struct my_builtins
{
char *name;
int (*func)(void);
} my_builtins;*/


 /* Funtions */

char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif /* MAIN_H */
