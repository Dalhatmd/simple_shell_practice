#include "shell.h"
int g_ac;
int main(int ac, char *av[])
{
	char *lineptr = NULL;
	size_t n;
	ssize_t nchars_read;

	(void)av;
	g_ac = ac;

	n = 0;

	while (1)
	{
		prompt();
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			printf("Exiting Shell... \n");
			exit(-1);
		}
		lineptr[strcspn(lineptr, "\n")] = '\0';

		input(lineptr);
	}
	free(lineptr);
	return (0);
}
