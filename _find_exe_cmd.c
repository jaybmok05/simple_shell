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
	struct stat sb;

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
		exe_path = malloc(strlen(token) + strlen(command) + 2);
		sprintf(exe_path, "%s:%s", token, command);

		if (stat(exe_path, &sb) == 0 && sb.st_mode & S_IXUSR)
		{
			return (exe_path);
		}
		free(exe_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
