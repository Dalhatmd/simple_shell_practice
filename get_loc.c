#include "shell.h"

char *get_location(char *command)
{
	char *path, *dir;

	path = "/bin/";
	dir = (char *) malloc(1 + strlen(path) + strlen(command));
	strcpy(dir, path);
	strcat(dir, command);
	return (dir);
}
