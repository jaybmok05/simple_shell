#include "myshell.h"

/**
 * _strtol - converts a string representation of a number to integer value
 * @str: string to convert
 * @endptr: pointer to first character that is not part of converted number
 * @base: base of a number system to be used
 * Return: long
 */

long _strtol(const char *str, char **endptr, int base)
{
	long result = 0;
	int sign = 1;
	bool found_digit = false;
	int digit;

	/*skip leading whitespace*/
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	/*check for optional sign*/
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}

	/* Check for base prefix*/
	if (base == 0)
	{
		if (*str == '0')
		{
			if (str[1] == 'x' || str[1] == 'X')
			{
				base = 16;
				str += 2;
			}
			else
			{
				base = 8;
				str++;
			}
		}
		else
		{
			base = 10;
		}
	}
	else if (base == 16 && *str == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		str += 2;
	}

	/*Process digits*/
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'z')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'Z')
			digit = *str - 'A' + 10;
		else
			break;

		if (digit >= base)
			break;

		result = result * base + digit;
		found_digit = true;
		str++;
	}

	/* set endptr if provided */

	if (endptr != NULL)
	{
		*endptr = (found_digit) ? (char *)str : (char *)str - 1;
	}

	return (sign * result);
}
