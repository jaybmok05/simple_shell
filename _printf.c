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
