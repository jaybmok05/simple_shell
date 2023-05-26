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
#include <ctype.h>
#include <errno.h>
#include <dirent.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define MAX_ALIASES 100
#define MAX_ALIAS_LENGTH 100

typedef struct {
	char name[MAX_ALIAS_LENGTH];
	char value[MAX_ALIAS_LENGTH];
} alias_t;

alias_t aliases[MAX_ALIASES];
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
long _strtol(const char *str, char **endptr, int base);
int set_env(const char *name, const char *value, int overwrite);
int _unset_env(const char *name);
char *_strchr(const char *str, int c);

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
int _print_int(int num);
int _puts(char *str);
int _strncmp(const char *str1, const char *str2, size_t len);
int _isspace(int c);
int alias_cmd(int argc, char* argv[]);
void add_alias(char* name, char* value);
void print_aliases();
void print_alias(alias_t alias);
#endif /* MY_SHELL_H */
