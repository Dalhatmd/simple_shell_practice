#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>

void input(void);
void execmd(char **argv);
void cleanup(char **argv);
void exit_shell(void);
void prompt(void);
char *get_location(char *command);
void parse_input(char **argv);
int check_built(char **argv);
void exec_builtin(char **argv);
void handle_command(const char *command);
void print_env(void);


#endif /*SHELL_H*/
