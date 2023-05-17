#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void execute(char **argv);
char *get_location(char *command);
void my_exit(char **argv);


#endif /*SHELL_H*/
