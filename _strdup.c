#include "myshell.h"

/**
 * _strdup -a function that duplicates a str in the heap memory.
 * @str: char pointer str.
 * Return: return the duplicated str.
 */

char *_strdup(const char *str)
{
	size_t len = _strlen(str);
	char *new = malloc(sizeof(char) * (len + 1));

	switch (new != NULL)
	{
	case 1:
		mem_cpy(new, str, len + 1);
		return (new);
	default:
		return (NULL);
	}
}
