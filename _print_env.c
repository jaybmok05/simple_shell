#include "myshell.h"

/**
 * print_env - prints environment of the current process
 */
extern char **environ;

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
