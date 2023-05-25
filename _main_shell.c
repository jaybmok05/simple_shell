#include "myshell.h"

/**
 * main - the main starting point for the shell
 * @argc: the count of arguments from argv
 * @argv: this is the vector of arguments
 * Return: returns 0 on success
 */

int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t cmd_size = 0;
	ssize_t read;

	/* check if the shell is running in interative node */

	if (isatty(STDIN_FILENO))
	{

		do {
			display_prompt();
			fflush(stdout);

			if (own_getline(&command, &cmd_size, stdin) == -1)
			{
				/* End of file (Ctrl+D) reached */
				break;
			}

			/* the trailing newline character is removed*/
			remove_newline(command);

			/* take the command to tokenization and execution */
			command_exe(command, argc, argv);

		} while (1);

	}
	else
	{
		while ((read = own_getline(&command, &cmd_size, stdin)) != -1)
		{
			if (command[read - 1] == '\n')
			{
				command[read - 1] = '\0';
			}

			command_exe(command, argc, argv);
		}
	}

	free(command);
	return (EXIT_SUCCESS);
}


/**
 * display_prompt - this function displays the prompt for the user
 */

void display_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
