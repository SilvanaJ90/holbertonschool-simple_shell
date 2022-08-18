#include "main.h"
#include <string.h>

/**
 * _strcpy - check the code
 * @dest: paste
 * @src: copy
 * Description: copy src to dest
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - description strlen calcula the length of a string
 *
 * @s: funtion calcula length of the string pointed to by s
 *
 * Return: the strlen function return of bytes in the string pointed to by s
 */

int _strlen(char *s)
{
	unsigned int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
		return (count);
}

/**
 * _strcat - check the code
 * @dest: string one
 * @src: add string to string one
 * Description: add src to dest
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	char *saved = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest++ = *src++) != '\0')
	{
		continue;
	}
	return (saved);
}


/**
 * _strcmp - check code compara dos cadenas
 * @s1: cadena 1
 * @s2: cadena 2
 * Return: Always 0 si == s2
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s2[i] != '\0' && s1[i] != 0; i++)
	{
		if (s1[i] != s2[i])
			break;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - check code
 * @str: value string
 * Return: new Pointer
 */

char *_strdup(char *str)

{
	int x;
	int y;
	char *newstr;

	if (str == NULL)
		return (NULL);

	for (x = 0; str[x] != '\0'; x++)
	{
	}
	x++;
	newstr = malloc(sizeof(char) * (x + 1));

	if (newstr == NULL)
		return (NULL);

	for (y = 0; y < x; y++)
	{
		newstr[y] = str[y];
	}
	newstr[y] = '\0';
	return (newstr);
}
