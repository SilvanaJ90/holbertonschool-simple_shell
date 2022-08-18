#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * _path - check code
 * @command: value
 * Return: always 0
 */

char *_pathSh(char *command)
{
	char *path, *copyPath, *pathToken, *dir;
	int commandlen, dirLen;
	struct stat tesfile;

	if (command[0] == '/' || command[0] == '.')
		if (stat(command, &tesfile) == 0)
			return (command);

	path = getenv("PATH");
	if (path)
	{
		copyPath = strdup(path);
		commandlen = _strlen(command);
		pathToken = strtok(copyPath, ":");
		while (pathToken != NULL)
		{
			dirLen = _strlen(pathToken);
			dir = malloc(dirLen +  commandlen + 2);
			_strcpy(dir, pathToken);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");

			if (stat(dir, &tesfile) == 0)
			{
				free(copyPath);
				return (dir);
			}
			free(dir);
			pathToken = strtok(NULL, ":");
		}
		free(copyPath);
		if (stat(command, &tesfile) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
