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
#include <dirent.h>

#define BUFFER_SIZE 1024

/* list of function prototypes */

void command_exe(char *command, int argc, char *argv[]);
void display_prompt(void);
char *find_exe(char *command);
char *find_exe_in_dir(const char *directory, const char *command);
char *construct_path(const char *directory, const char *command);
int exit_shell(char **args);
void print_env(void);
void change_dir(int argc, char *argv[]);

ssize_t own_getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void assign_chars(char **lineptr, size_t *line_s,
char *buffer, size_t buf_size);

size_t _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, char *src);

#endif /* MY_SHELL_H */
