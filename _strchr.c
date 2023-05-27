#include "myshell.h"

/**
 * _strchr - searches for the fisrt occurance of a character in a string
 * @str: pointer to string to search
 * @c: character searhing for
 * Return: pointer to the first occurance of the character
 */

char *_strchr(const char *str, int c)
{
	if (str == NULL)
	{
		return (NULL);
	}

	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}

	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
