#include "shell.h"

/**
 * get_location - Function to find path of executable file.
 * @command: Parameter.
 * Return: Path of executable file.
 */

char *get_location(char *command)
{
	char *path, *dir;

	path = "/bin/";
	dir = (char *) malloc(1 + strlen(path) + strlen(command));
	strcpy(dir, path);
	strcat(dir, command);
	return (dir);
}
