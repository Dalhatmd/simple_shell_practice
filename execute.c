#include "shell.h"
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t pid;
	int status;

	status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];
        		actual_command = get_location(command);
        		if (execve(actual_command, argv, NULL) == -1)
			{
            		perror("Error:");
        		}
    		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
}
