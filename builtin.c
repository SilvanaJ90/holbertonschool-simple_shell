#include "main.h"

/**
 * _builtin -check code
 * @args: value
 * Return: always 0
 */

int _builtin(char **args)
{
	int numBuiltin = 0;
	int i;

	builtin builtins[] = {
		{"exit", _eexit},
		{"cd", _cd},
		{"help", _help},
		{"env", _env},
	};


	numBuiltin = sizeof(builtins) / sizeof(struct builtin);

	for (i = 0; i < numBuiltin; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

/**
 * _eexit - check code
 * @args: value
 */

void _eexit(char **args __attribute__((unused)))
{
	exit(0);
}

/**
 * _cd -check code
 * @args: value
 */

void _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: cd: missing argument\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh: cd");
		}
	}
}


/**
 * _help -check code
 * @args: value
 */

void _help(char **args __attribute__((unused)))
{
	char *helptext =
		"The following commands are available:\n"
		"  cd       Change the working directory.\n"
		"  exit     Exit the shell.\n"
		"  help     Print this help text.\n";
	printf("%s", helptext);
}

/**
 * _env -check code
 * @args: value
 */

void _env(char **args __attribute__((unused)))
{
	char **env = environ;
	int i = 0;

	while (env[i])
		printf("%s\n", env[i]);
	i++;
}
