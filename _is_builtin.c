#include "myshell.h"

/**
 * is_builtin - cheks if command given is builtin or not
 * @args: pointer to tokenized command string
 * Return: 1 if it is a builtin, 0 otherwise
 */

int is_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "env") == 0 ||
			strcmp(args[0], "cd") == 0 || strcmp(args[0], "setenv") == 0 ||
			strcmp(args[0], "unsetenv") == 0)
	{
		return (1);
	}
	return (0);
}
