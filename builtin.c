#include "main.h"
#include <stdlib.h>

void _builtin(char **args)
{
	int numBuiltin = 0;
	int i;

	struct builtin builtins[] = {
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
			return;
		}
	}
}

void _eexit(char **args)
{
	(void)args;
		exit(0);
}

void _cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "hsh: cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("hsh: cd");
        }
    }
}

void _help(char **args) {
    char *helptext =
        "The following commands are available:\n"
        "  cd       Change the working directory.\n"
        "  exit     Exit the shell.\n"
        "  help     Print this help text.\n";
    printf("%s", helptext);

    (void)args;
}

void _env(char **args)
{
    char **env = environ;

    /*for (; *s; s++) {
        printf("%s\n", *s);
    };*/
    while (*env)
      printf("%s\n", *env++);


    (void)args;
}