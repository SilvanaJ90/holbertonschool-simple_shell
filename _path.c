#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *
 *
 *
 *
 *
 */

char *_path(char *command)
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
		commandLen = _strlen(command);
		pathToken = _strtok(copyPath, ":");
		while (pathToken != NULL)
		{
			dirLen = _strlen(pathToken);
			dir = malloc(dirLen + commandLen + 2);
			_strcat(dir, pathToken);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");

			if(stat(dir, &tesfile) == 0)
			{
				free(copyPath);
				return (dir);
			}
			free(dir);
			pathToken = strtok(NULL, ":");
		}
		free(copyPath);
		if (stat(command, &testfile) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
