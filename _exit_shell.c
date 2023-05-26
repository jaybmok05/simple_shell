#include "myshell.h"

/**
 * exit_shell - terminates the shell
 * @args: pointer to tokenized command string
 * Return: 0
 */

int exit_shell(char **args)
{
	int exit_status = EXIT_SUCCESS;
	char *endptr;
	int line_count = 1;

	if (args[1] != NULL)
	{
		exit_status = _strtol(args[1], &endptr, 10);

		/*check if strtol encountered an erro*/

		if (*endptr != '\0' || exit_status == 0)
		{
			_printf("./hsh: %d: exit: Illegal number: %s\n", line_count, args[1]);
			return (0);
		}

		/*Check if the exit status is out of range*/

		if (exit_status < 0)
		{
			_printf("./hsh: %d: exit: Illegal number: %d\n", line_count, exit_status);
			return (0);
		}

		if (exit_status > 225)
		{
			exit_status = 232;
		}
	}

	free(args[0]);
	line_count++;
	exit(exit_status);
}
