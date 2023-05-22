#include "shell.h"
void exec_builtin(char **argv)
{
	if (strcmp(argv[0], "exit") == 0 && !argv[1])
		exit(0);
}
