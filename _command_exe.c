#include "myshell.h"

/**
 * command_exe - this function will simply execute the command
 * passed.
 * @args: pointer to tokenized command to execute
 */


void command_exe(char **args)
{
	char *path;
	pid_t pid;
	int status;

	/* Find the path of the executable */
	path = find_exe(args[0]);

	/*check if path is available*/
	if (path == NULL)
	{
		printf("Error: ahh!! command not found:\n");
		return;
	}
	/* Create a child process to execute the command */
	pid = fork();

	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execv(path, args) == -1)
		{
			perror("Failed to execute command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}
	free(path);
}
