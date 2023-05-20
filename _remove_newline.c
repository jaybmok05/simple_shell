#include "myshell.h"

/**
 * remove_newline - replaces newline by null character
 * @command: string that end with newline read from command line
 */

void remove_newline(char *command)
{
	int i = 0;

	for (; command[i] != '\0'; i++)
	{
		if (command[i] == '\n')
		{
			command[i] = '\0';
			break;
		}
	}
}
