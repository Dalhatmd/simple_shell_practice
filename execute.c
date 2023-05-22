#include "shell.h"
/**
 * execute - executes command line arguments
 *
 * @argv: command line args
 */
void execute(char **argv)
{
	int access_result, status;
	pid_t pid;
	char *command = NULL, *actual_command = NULL,*path;
	path = getenv("PATH");

	pid = fork();
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];
			actual_command = get_location(command);

			access_result = access(actual_command, F_OK);
			if (access_result == -1)
			{
				dprintf(STDERR_FILENO, "%s: 1: %s not found\n", path, command);
				exit(EXIT_FAILURE);
			}

			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

void parse_input(char **argv)
{
    int argc = 0;
    char *token = strtok(argv[0], " \t\n");
    while (token != NULL) {
        argv[argc] = token;
        argc++;
        token = strtok(NULL, " \t\n");
    }
    argv[argc] = NULL;
}

