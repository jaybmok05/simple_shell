#include "myshell.h"

/**
 * _strlen - determines the length of a string
 * @str: pointer to the string whose length is to be found
 * Return: length of a string
 */

size_t _strlen(const char *str)
{
	size_t count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
