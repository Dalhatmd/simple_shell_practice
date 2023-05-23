#include "shell.h"

/**
 * check_built - Function that checks whether a command is built in or not.
 * @argv: Parameter (the command to be checked).
 *
 * Return: 1 if command is built-in, 0 if not.
 */

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
