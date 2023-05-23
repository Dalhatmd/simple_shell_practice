#include "shell.h"

/**
 * cleanup - Function that free a space dynammically allocated to an array.
 * @argv: Parameter (the array of commands to be freed).
 * 
 * Return: Nothing (it's a viod function).
 */

void cleanup(char **argv)
{
	int i;
	if (argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
}
