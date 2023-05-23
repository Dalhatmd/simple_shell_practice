#include "shell.h"
int check_built(char **argv)
{
	int i;
	char *built_in[] = {"cd", "exit", "setenv", "unsetenv"};

	for (i = 0; built_in[i] != NULL; i++)
	{
		if (strcmp(built_in[i], argv[0]) == 0)
			return (1);
	}
	return (0);
}
