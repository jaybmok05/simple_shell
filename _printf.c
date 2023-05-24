#include "myshell.h"

/**
 * _puts - a function that prints a string
 * Return: the number of characters printed
 * @str: the string to print
 */

int _puts(char *str)
{
	int index, char_count = 0;

	/* Loop over the string */
	for (index = 0; str[index] != '\0'; index++)
	{
		/* Call write to print the current character and increment the count */
		char_count += write(1, &str[index], 1);
	}

	/* Return the count of characters printed */
	return (char_count);
}

/**
 * _printf - a function that produces output according to a format.
 * Return: the number of characters printed
 * @format: the format string
 */

int _printf(const char *format, ...)
{
	char *str;
	int index, char_count = 0;
	va_list args;

	va_start(args, format);

	/* Check if the format pointer is NULL */
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}

	/* Loop over the format string */
	for (index = 0; format[index] != '\0'; index++)
	{
		/* Check if the current character is a format specifier % */
		if (format[index] == '%')
		{
			index++;
			if (format[index] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				char_count += _puts(str);
			}
			else if (format[index] == 'd' || format[index] == 'i')
			{
				char_count += _print_int(va_arg(args, int));
			}
			else if (format[index] == '%')
			{
				char_count += write(1, &format[index], 1);
			}
		}
		else
		{
			char_count += write(1, &format[index], 1);
		}
	}

	va_end(args);
	return (char_count);
}


/**
 * _print_int - a function that prints an integer to stdout
 * Return: the number of characters printed
 * @num: the list of arguments
 */

int _print_int(int num)
{
	int is_negative = num < 0 ? 1 : 0;
	unsigned int num_u = is_negative ? -num : num;
	char *str;
	int i, j, k, len = 0;
	char tmp;

	/* the number of digits are counted*/
	i = num_u;
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	/* add an extra digit*/
	if (is_negative)
	{
		len++;
	}
	str = malloc(len + 1);

	/* convert the number to a string */
	for (i = num_u, j = 0; i > 0; i /= 10, j++)
	{
		str[j] = i % 10 + '0';
	}
	if (is_negative)
	{
		str[j++] = '-';
	}
	str[j] = '\0';

	/*the string is reversed*/
	for (k = 0, j--; k < j; k++, j--)
	{
		tmp = str[k];
		str[k] = str[j];
		str[j] = tmp;
	}
	/* print the string */
	len = _puts(str);
	free(str);
	return (len);
}
