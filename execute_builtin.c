#include "shell.h"

/**
 * exec_builtin - Function that checks if the command is "exit".
 *
 * @argv: Parameter (the command to check).
 */

void exec_builtin(char **argv)
{
	if (strcmp(argv[0], "exit") == 0 && !argv[1])
		exit_shell();
}
