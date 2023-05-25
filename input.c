#include "shell.h"
void input(void)
{
	char *line = NULL, *command, *argument, *command_path;
	size_t bufsize;
	ssize_t nread;

	bufsize = 0;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &bufsize, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("Exiting shell...\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		line[strcspn(line, "\n")] = '\0';
		command = strtok(line, " ");
		argument = strtok(NULL, " ");

		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
			{
				int exit_status;
				exit_status = 0;
				if (argument != NULL)
					exit_status = atoi(argument);
				exit(exit_status);
			}
			else if (strcmp(command, "env") == 0)
				print_env();
			command_path = get_location(command);
			if (command_path != NULL)
			{
				execute(command_path, argument);
				free(command_path);
			}
			else
			{
				printf("Command not found: %s\n", command);
			}
		}
	}
}
