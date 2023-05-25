#include "shell.h"
void execmd(char **argv)
{
    char *command = NULL, *actual_command = NULL;
    pid_t pid;
    int status;
    char **new_argv;
    int i;

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

            if (execve(command, argv, NULL) == -1)
            {
                if (strncmp(command, "/bin/", 5) == 0)
                {
                    if (execve(command + 5, argv, NULL) == -1)
                    {
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    actual_command = get_location(command);
                    if (actual_command != NULL)
                    {
                        int num_tokens = 0;
                        for (i = 0; argv[i] != NULL; i++)
                        {
                            num_tokens++;
                        }

                        new_argv = malloc(sizeof(char *) * (num_tokens + 1));
                        new_argv[0] = actual_command;
                        for (i = 1; argv[i] != NULL; i++)
                        {
                            new_argv[i] = argv[i];
                        }
                        new_argv[num_tokens] = NULL;

                        if (execve(actual_command, new_argv, NULL) == -1)
                        {
                            perror("execve");
                            exit(EXIT_FAILURE);
                        }

                        free(new_argv);
                    }
                    else
                    {
                        printf("Command: %s not found\n", command);
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
    }
}

