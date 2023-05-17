#include "myshell.h"

/**
 * print_env - prints variables of the current environment
 */

extern char ** environ;

void print_env(void)
{
	/* Get the current environment variables */
	char **env = environ;

	/* Print each environment variable */
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
