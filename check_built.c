#include "shell.h"
void check_built(char **argv)
{
	int i;
	char *built_in[] = {"cd", "exit", "setenv", "unsetenv"};

	for (i = 0; built_in[i] != NULL; i++)
	{
		if (strcmp(argv[0], built_in[i]) == 0)
		{
			exec_builtin(argv);
		}
	}
}

