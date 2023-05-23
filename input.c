#include "shell.h"
void input(char *input)
{
	char **argv = NULL;
	int argv_size;
	int argc;
	char *token;
	int i;

		argv_size = 2;
		argc = 0;

		argv = malloc(sizeof(char *) * argv_size);
		if (argv == NULL)
		{
			perror("Shell: Memory allocation error");
			exit (-1);
		}
		token = strtok(input, "\n");
		while (token != NULL)
		{
			argv[argc] = malloc(strlen(token) + 1);
			if (argv[argc] == NULL)
			{
				perror("Shell: Memory allocation error");
				exit(-1);
			}
			strcpy(argv[argc], token);
			argc++;

			if (argc >= argv_size)
			{
				int new_size = argv_size * 2;
				char **new_argv = malloc(sizeof(char *) * new_size);
				for (i = 0; i < argc; i++)
				{
					new_argv[i] = malloc(strlen(argv[i] + 1));
				strcpy(new_argv[i], argv[i]);
				}
				free(argv);
				argv = new_argv;
				argv_size = new_size;
			}
			token = strtok(NULL, "\n");
		}
		argv[argc] = NULL;

		parse_input(argv);
/*		if (check_built(argv) == 1)
			exec_builtin(argv);
		else
		{*/
		execute(argv);
//		}

		cleanup(argv);
}
