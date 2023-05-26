#include "myshell.h"

/**
 * _unset_env - removes/clears the set environment variable
 * @name: name of the environment variable to unset
 * Return: 0 0n success, -1 otherwise
 */

int _unset_env(const char *name)
{
	char **src, **dest;
	char **env = environ;

	if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL)
	{
		perror("Invalid variable name\n");;
		return (-1);
	}

	/*Iterate over the environment variable*/
	while (*env != NULL)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
		{
			/*remove the variable by shifting the following variable*/
			src = env + 1;
			dest = env;
			while (*src != NULL)
			{
				*src = *dest;
				src++;
				dest++;
			}
			*dest = NULL;
			break;
		}
		env++;
	}
	return (0);
}
