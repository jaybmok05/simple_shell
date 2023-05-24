#include "myshell.h"

/**
 * cmp_chars - a function that compares chars in a string
 * to check for delimeter
 * @str: the string
 * @delim: the delimeter
 * Return: returns 1 if match, 0 if not.
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int str_index = 0;
	unsigned int delim_index = 0;
	unsigned int match_count = 0;

	while (str[str_index] != '\0')
	{
		while (delim[delim_index] != '\0')
		{
			if (str[str_index] == delim[delim_index])
			{
				match_count++;
				break;
			}
			delim_index++;
		}
		str_index++;
	}

	if (str_index == match_count)
	{
		return (1);
	}

	return (0);
}
