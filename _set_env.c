#include "myshell.h"

/**
 * set_env - creates new environment variable or modify an existing one
 * @name: name of the evvironment variable
 * @value: is what is assigned to environment variable
 * @overwrite: determines whether to change a variable name or not
 * Return: 0 on success, -1 otherwise
 */

int set_env(const char *name, const char *value, int overwrite)
{
	int result;
	char *new_var;
	char *existing_var;
	size_t name_len, value_len, var_len;

	if (name == NULL || value == NULL)
		return (-1);

	/* check if the environment variable already exits */
	existing_var = _getenv(name);
	if (existing_var)
	{
		if (overwrite == 0)
			return (-1);
	}

	/* calculate the size required for the new environ variable*/
	name_len = _strlen(name);
	value_len = _strlen(value);
	var_len = name_len + value_len + 2;

	/* Allocate memory for the new environment variable*/
	new_var = malloc(var_len);
	if (new_var == NULL)
		return (-1);
	/*create the new environment variable in the format "NAME=VALUE"*/
	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);

	/* update the environment with the new variable*/
	result = putenv(new_var);
	if (result != 0)
	{
		free(new_var);
		return (-1);
	}

	return (0);
}
