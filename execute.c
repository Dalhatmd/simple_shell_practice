#include "shell.h"
/**
 * execute - executes command line arguments
 *
 * @argv: command line args
 */
void execute(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
			dprintf(STDERR_FILENO, "Error:");
	}
}
