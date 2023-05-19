#include "myshell.h"

/**
 * find_exe - finds an exexutable file where a command is defined
 * @command: pointer to the command
 * Return: path to the exacutable
 */

char *find_exe(char *command)
{
	char *path, *token, *exe_path, *cwd_path;
	char cwd[PATH_MAX];

	path = getenv("PATH");

	cwd_path = malloc(PATH_MAX + strlen(path) + 2);
	if (cwd_path == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	if  (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		free(cwd_path);
		return (NULL);
	}

	sprintf(cwd_path, "%s:%s", cwd, path);

	token = strtok(cwd_path, ":");

	while (token != NULL)
	{
		exe_path = find_exe_in_dir(token, command);
		if (exe_path != NULL)
		{
			free(cwd_path);
			return (exe_path);
		}
		free(exe_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
