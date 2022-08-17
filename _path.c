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
	int command length, dirLength;
	struct stat tesfile;

	if (command[0] == '/' || command[0] == '.')
		if (stat(command, &tesfile) == 0)
			return (command);

	path = getenv("PATH");
	if (path)
	{
		copyPath = strdup(path);
		commandLeng
	}
}
