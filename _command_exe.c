#include "myshell.h"

/**
 * command_exe - this function will simply execute the command
 * passed.
 * @command: the command to execute
 */

void command_exe(int __attribute__((__unused__)) argc, char *argv[])
{
	char *token, *path;
	pid_t pid;
	int status, index = 0;
	char *args[BUFFER_SIZE];
	
	/* Tokenize the command string */
	token = strtok(argv[0], " ");
	while (token != NULL)
	{
		args[index++] = token;
		token = strtok(NULL, " ");
	}
	
	/* Mark the end of the arguments array with NULL */
	args[index] = NULL;
	
	/** Check if the command is 'cd'
	 * if (strcmp(args[0], "./cd") == 0)
	 * {
	 * cd_command(args[1]);
	 * return;
	 * }
	 */

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
