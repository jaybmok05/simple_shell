#include "myshell.h"

/**
 * command_exe - this function will simply execute the command
 * passed.
 * @command: the command to execute
 * @argc: the number of arhuments
 * @argv: the vector array of arguments
 */

void command_exe(char *command, int argc, char *argv[])
{
	char *token, *path;
	pid_t pid;
	int status, result, index = 0;
	char *args[BUFFER_SIZE];

	while (_isspace(*command))
		command++;

	if (_strlen(command) == 0)
	{
		return;
	}

	/* Tokenize the command string */
	token = _strtok(command, " ");
	while (token != NULL && index < BUFFER_SIZE - 1)
	{
		args[index++] = token;
		token = _strtok(NULL, " ");
	}

	/* Mark the end of the arguments array with NULL */
	args[index] = NULL;

	/* check if the command is one of builtins and execute */

	if (_strcmp(args[0], "exit") == 0)
	{
		exit_shell(args);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		change_dir(argc, argv);
		return;
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (index >= 3)
		{
			result = set_env(args[1], args[2], 1);
			if (result == -1)
			{
				_printf("failed to set environment variable: %s\n", args[1]);
			}
		}
		return;
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (index >= 2)
		{
			result = _unset_env(args[1]);
			if (result == -1)
			{
				_printf("failed to unset environment variable: %s\n", args[1]);
			}
		}
		return;
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		alias_cmd(argc, argv);
		return;
	}



	/* Find the path of the executable */
	path = find_exe(args[0]);

	/*check if path is available*/
	if (path == NULL)
	{
		_printf("%s: %d: %s: not found\n", argv[0], (__LINE__ - 50), args[0]);
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
		if (execve(path, args, environ) == -1)
		{
			perror("Failed to execute command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);

		/* check if the command failed*/
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			_printf("./hsh: command failed: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	free(path);
}
