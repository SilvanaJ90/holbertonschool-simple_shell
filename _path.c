#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * _pathSh - check code
 * @command: value
 * Return: always 0
 */

char *_pathSh(char *command)
{
	char *path, *copyPath = NULL, *pathToken = NULL, *dir = NULL;
	int commandlen = _strlen(command), dirLen = 0;
	struct stat tesfile;

	if (stat(command, &tesfile) == 0)
		return (command);

	path = getenv("PATH");
	if (path)
	{
		copyPath = _strdup(path);
		if (!copyPath)
			return (NULL);
		pathToken = strtok(copyPath, ":");
		while (pathToken != NULL)
		{
			dirLen = _strlen(pathToken) + commandlen + 1;
			dir = malloc(sizeof(char) * dirLen + 1);
			if (!dir)
				return(NULL);
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
		return (NULL);
	}
	return (NULL);
}
