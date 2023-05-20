#include "myshell.h"

/**
 * _strcmp - compares two strings
 * @str1: 1st string
 * @str2: 2nd string
 * Return: 0 if they are the same, non-zero integer otherwise
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;
	int strcmp;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		strcmp = str1[i] - str2[i];
		if (strcmp != 0)
		{
			return (strcmp);
		}
		i++;
	}
	return (0);
}
