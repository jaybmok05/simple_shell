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

	do {
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/* End of file (Ctrl+D) reached */
			printf("\n");
			break;
		}

		/* the trailing newline character is removed*/
		command[strcspn(command, "\n")] = '\0';

		if (argc == 1)
		{
			/*Handles commands with no arguments*/
			command_exe(1, argv);
		}
		else
		{
			/*argv[0] = command, argv[1] 1st arguments...argv[N]*/
			command_exe(argc, argv);
		}
	} while (1);

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
