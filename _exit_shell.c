#include "myshell.h"

/**
 * exit_shell - exits the shell
 * When this function is executed the shell disconnects
 * No command prompt is displayed
 */

void exit_shell(void)
{
	printf("Disconnected...\n");
	exit(EXIT_SUCCESS);
}
