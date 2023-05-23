#include "myshell.h"

/**
 * _strncmp - compares two strings up to a certain length
 * @str1: first string
 * @str2: second string
 * @len: length/number of characters to compare from both strings
 * Return: 0 if trings are equal up to len
 */

int _strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i;

	if (len == 0)
	{
		return (0);
	}

	if (str1 == NULL && str2 == NULL)
	{
		return (0);
	}
	else if (str1 == NULL)
	{
		return (-1);
	}
	else if (str2 == NULL)
	{
		return (1);
	}

	for (i = 0; i < len - 1; i++)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] =='\0')
		{
			return (str1[i] - str2[i]);
		}
	}

	return (0);
}
