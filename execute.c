#include "shell.h"
/**
 * execute - executes command line arguments
 *
 * @argv: command line args
 */
void execute(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);

		if (execve(actual_command, argv, NULL) == -1)
			dprintf(STDERR_FILENO, "Error:");
	}
}
