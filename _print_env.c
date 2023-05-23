#include "myshell.h"

/**
 * print_env - prints environment of the current process
 */

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		env++;
	}
}
