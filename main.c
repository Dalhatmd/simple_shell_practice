#include "shell.h"

/**
 * main - Entry Point.
 * @ac: Parameter (the number of arguments aka argument count).
 * @av: Parameter (the array of command line arguments).
 *
 * Return: 0 for success.
 */

int main(int ac, char *av[])
{
	char *lineptr = NULL;
	size_t n;
	ssize_t nchars_read;

	(void)av;
	(void)ac;

	n = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
		}
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			printf("Exiting Shell... \n");
			exit(-1);
		}
		lineptr[strcspn(lineptr, "\n")] = '\0';

		input();
	}
	free(lineptr);
	return (0);
}
