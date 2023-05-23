#include "myshell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: name of the environment variable
 * Return: pointer to the value of the variable
 */

extern char **environ;

char *_getenv(const char *name)
{
	int i;
	size_t len;
	char * value = NULL;

	if (name == NULL || name[0] == '\0')
	{
		return (NULL);
	}

	len = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if(_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			value = environ[i] + len + 1;
			return (value);
		}
	}
	return (NULL);
}
