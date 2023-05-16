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
		
			/* take the command to tokenization and execution */
			command_exe(command, argc, argv);

		} while (1);

	}
	else
	{
		while (fgets(command, sizeof(command), stdin) != NULL)
		{
			command[strcspn(command, "\n")] = '\0';

			command_exe(command, argc, argv);
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