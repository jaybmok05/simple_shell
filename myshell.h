#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* list of function prototypes */

void command_exe(char *command, int argc, char *argv[]);
void display_prompt(void);
char *find_exe(char *command);

#endif /* MY_SHELL_H */
