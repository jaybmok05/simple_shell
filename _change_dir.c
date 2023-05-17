#include "myshell.h"

/**
 * change_dir - changes current directory of the process
 * @argc: No. of arguments passed on command line
 * @argv: Value/vector of arguments
 */

void change_dir(int argc, char *argv[])
{
	char *target_dir;
	char cwd[PATH_MAX], new_path[PATH_MAX];
	size_t new_path_size;


	/* change to target dir or home if no target dir given */
	if (argc > 1)
	{
		target_dir = argv[1];
	}
	else
	{
		target_dir = getenv("HOME");
	}

	/* change to previous dir if "-" is used as argv[1] */
	if (strcmp(target_dir, "-") == 0)
	{
		target_dir = getenv("OLDPWD");
		if (target_dir == NULL)
		{
			printf("No previous dir found");
			return;
		}
	}

	/* retrieve current working directory */
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("Can not current working directory");
		return;
	}
	/* check if target-dir is an absolute path */
	if (target_dir[0] == '/')
	{
		strncpy(new_path, target_dir, sizeof(new_path));
	}
	else
	{
		/* construnstruct a new path by contatinating cwd and target_dir */
		new_path_size = strlen(cwd) + strlen(target_dir) + 2;
		snprintf(new_path, new_path_size, "%s/%s", cwd, target_dir);
	}

	/* change directory to new path */
	if (chdir(target_dir) != 0)
	{
		perror("Failed to change directory");
		return;
	}

	/* keep track of previous working directory to enable back navigation*/
	if (setenv("OLDPWD", cwd, 1) != 0)
	{
		perror("Failed to set OLDPWD");
		return;
	}

	/* Set/update PWD */
	if (setenv("PWD", new_path, 1) != 0)
	{
		perror("Failed to set PWD");
		return;
	}

}
