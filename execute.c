#include "shell.h"
/**
 * execute - executes command line arguments
 *
 * @argv: command line args
 */
void execute(char *command_path, char *argument)
{
	char *args[3];
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = command_path;
		args[1] = argument;
		args[2] = NULL;

		if (execve(command_path, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}



/**
 * parse_input - Function that tokenizes the command input into strings.
 * @argv: Parameter (the command to split).
 */

void parse_input(char **argv)
{
	int argc;
	char *token;

	argc = 0;
	token = strtok(argv[0], " \t\n");
	while (token != NULL)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;
}

