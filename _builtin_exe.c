#include "myshell.h"

/**
 * builtin_com_exe - executes only builtin commands
 * @args: pointer to tokenized command string
 */

void builtin_com_exe(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit_shell();
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	/*else if (strcmp(args[0], "cd") == 0)
	{
		change_dir(argc, args);
	}*/
	else
	{
		printf("Error: command not found\n");
	}

}
