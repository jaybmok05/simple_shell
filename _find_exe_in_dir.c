#include "myshell.h"

/**
 * find_exe_in_dir - a function performs the directory
 * iteration for a specific directory
 * @directory: the directory to iterate and search in.
 * @command: the command to look for
 * Return: returns the path/executable if successful
 */

/*this function will search for executale in the directory "/bin"*/
char *find_exe_in_dir(const char *directory, const char *command)
{
	char *path;
	/*Open the specified directory and obtain a pointer to a DIR structure*/
	DIR *dir = opendir(directory);
	struct stat sb;
	/*Declare a structure to represent directory entries*/
	struct dirent *entry;

	if (dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}

	/* we are iterating through each directory entry*/
	while ((entry = readdir(dir)) != NULL)
	{
		/*check if the command enter is in the directory entry*/
		if (_strcmp(entry->d_name, command) == 0)
		{
			/*make the full path "path_dir/command"*/
			path = construct_path(directory, command);
			if (path != NULL)
			{
				if (access(path, X_OK) == 0 && stat(path, &sb) == 0 && S_ISREG(sb.st_mode))
				{
					closedir(dir);
					/*we return the executable*/
					return (path);
				}
				free(path);
			}
		}
	}

	closedir(dir);
	return (NULL);
}


/**
 * construct_path - function takes a directory and a command, and
 * constructs the full path by concatenating them together with a
 * slash (/) in between.
 * @directory: the directory carrying the command
 * @command: the command
 * Return: returns the path having the command
 */

/*with this function we create the full path to the commands*/
char *construct_path(const char *directory, const char *command)
{
	size_t directory_len = _strlen(directory);
	size_t command_len = _strlen(command);
	char *path = malloc(directory_len + command_len + 2);

	if (path != NULL)
	{
		/*construct the full path "direectory/command*/
		_sprintf(path, "%s/%s", directory, command);
	}

	return (path);
}
