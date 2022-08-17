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

 /* Funtions */

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif /* MAIN_H */
