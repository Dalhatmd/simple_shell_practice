#ifndef SHELL_H
#define SHELL_H

extern int g_ac;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void input(char *input);
void execute(char **argv);
void cleanup(char **argv);
void exit_shell(void);
void prompt(void);
char *get_location(char *command);


#endif /*SHELL_H*/
