#include "myshell.h"

/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 * Return: 0 if no int found
 */

int _atoi(char *str)
{
	int i = 0, signal = 1;
	unsigned int res = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
		{
			signal *= -1;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res + str[i] - '0';
			if ((*(str + (i + 1)) >= '0') && (*(str + (i + 1)) <= '9'))
			{
				res *= 10; 
			}
			else
				break;
		}
	}
	return (res * signal);
}
