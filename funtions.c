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
