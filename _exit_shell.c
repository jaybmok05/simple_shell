#include "myshell.h"

/**
 * exit_shell - terminates the shell 
 * @args: pointer to tokenized command string
 * Return: 0
 */

int exit_shell(char **args)
{
	int exit_status = EXIT_SUCCESS;

	if (args[1] != NULL)
	{
		exit_status = atoi(args[1]);
	}

	exit(exit_status);
}
