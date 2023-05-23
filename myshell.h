#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024

extern char **environ;

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
void remove_newline(char *command);
char *_strtok(char str[], const char *delim);
bool is_delimiter(char c, const char *delim);
int cmp_chars(char str[], const char *delim);
int _sprintf(char *buffer, const char *format, ...);
char *_getenv(const char *name);
int _atoi(char *str);
char *_strdup(const char *s);
void mem_cpy(void *destination, const void *source, unsigned int size);
int _printf(const char *format, ...);
int _puts(char *str);
int _strncmp(const char *str1, const char *str2, size_t len);

#endif /* MY_SHELL_H */
