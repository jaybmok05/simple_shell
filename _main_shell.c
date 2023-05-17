#include "myshell.h"

/**
 * main - the main starting point for the shell
 * @argc: the count of arguments from argv
 * @argv: this is the vector of arguments
 * Return: returns 0 on success
 */

int main(int argc, char *argv[])
{
	char command[BUFFER_SIZE];
	char *token;
	int index = 0;
	char *args[BUFFER_SIZE];

	(void)argc;
	(void)argv;

	/* check if the shell is running in interative node */

	if (isatty(STDIN_FILENO))
	{

		do {
			display_prompt();
			fflush(stdout);

			if (fgets(command, sizeof(command), stdin) == NULL)
			{
				/* End of file (Ctrl+D) reached */
				printf("\n");
				break;
			}

			/* the trailing newline character is removed*/
			command[strcspn(command, "\n")] = '\0';

			/* Tokenize the command string */
			token = strtok(command, " ");
			while (token != NULL && index < BUFFER_SIZE - 1)
			{
				args[index++] = token;
				token = strtok(NULL, " ");
			}

			/* Mark the end of the arguments array with NULL */
			args[index] = NULL;

			/* check if a command is a builtin command and execute*/
			if (is_builtin(args))
			{
				builtin_com_exe(args);
			}
			else
			{
				command_exe(args);
			}

		} while (1);

	}
	else
	{
		while (fgets(command, sizeof(command), stdin) != NULL)
		{
			command[strcspn(command, "\n")] = '\0';

			token = strtok(command, " ");
			while (token != NULL && index < BUFFER_SIZE - 1)
			{
				args[index++] = token;
				token = strtok(NULL, " ");
			}

			args[index] = NULL;

			if (is_builtin(args))
			{
				builtin_com_exe(args);
			}
			else
			{
				command_exe(args);
			}
		}
	}

	return (0);
}



/**
 * display_prompt - this function displays the prompt for the user
 */

void display_prompt(void)
{
	char *prompt = "my_shell$ ";

	write(STDOUT_FILENO, prompt, strlen(prompt));
}
