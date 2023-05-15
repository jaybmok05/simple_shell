#include "myshell.h"

/**
 * command_exe - this function will simply execute the command
 * passed.
 * @command: the command to execute
 */

extern char **environ;

void command_exe(char *command, int argc, char *argv[])
{
	char *token, *path;
	pid_t pid;
	int status, index = 0;
	char *args[BUFFER_SIZE];
	char **env = environ;
	
	/* Tokenize the command string */
	token = strtok(command, " ");
	while (token != NULL && index < BUFFER_SIZE - 1) 
	{
		args[index++] = token;
		token = strtok(NULL, " ");
	}
	
	/* Mark the end of the arguments array with NULL */
	args[index] = NULL;

	/* check if the command is "exit" */

	if (strcmp(args[0], "exit") == 0)
	{
		printf("Disconnected...\n");
		exit(EXIT_SUCCESS);
	}

	/* check if the command is "env" */
	if (strcmp(args[0], "env") == 0)
	{
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return;
	}

	/* check if the command is "cd" */
	if (strcmp(args[0], "cd") == 0)
	{
		if (argc > 1)
		{
			if (chdir(argv[1]) != 0)
			{
				perror("Failed to change directory");
				return;
			}
		}
		else
		{
			printf("Usage: cd <directory>\n");
		}
		return;
	}

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
