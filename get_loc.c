#include "shell.h"

/**
 * get_location - Function to find path of executable file.
 * @command: Parameter.
 * Return: Path of executable file.
 */

char *get_location(const char *command)
{
	char *path, *path_copy, *path_token, command_path[BUFSIZE];
	struct stat buffer;

	path = getenv ("PATH");
	path_copy = strdup(path);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", path_token,command);
		
		if (stat(command_path, &buffer) == 0 && S_ISREG(buffer.st_mode))
		{
			free(path_copy);
			return (strdup(command_path));
		}
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
