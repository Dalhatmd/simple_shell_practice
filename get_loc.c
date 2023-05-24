#include "shell.h"
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int com_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	/*
	if (check_built(command))
	{
		exec_builtin(command);
		return;
	}
	*/
	if (path)
	{
		path_copy = strdup(path);
		com_len = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(com_len + dir_len);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);

	}

	return (NULL);
}
