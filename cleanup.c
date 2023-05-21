#include "shell.h"
void cleanup(void)
{
	int i;
	if (argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
}
