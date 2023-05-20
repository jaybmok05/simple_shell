#include "myshell.h"

/**
 * _sprintf - custom sprintf that only handles string format specifier
 * @buffer: stores formated string
 * @format: null terminated string
 * Return: No. of characters written to the buffer
 */

int _sprintf(char *buffer, const char *format, ...)
{
	va_list args;

	int count = 0;
	const char *str = NULL;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 's':
				{
					str = va_arg(args, const char*);
					while (*str)
					{
						*buffer++ = *str++;
						count++;
					}
					break;
				}
				default:
					break;
			}
		}
		else
		{
			*buffer++ = *format;
			count++;
		}
		format++;
	}
	va_end(args);
	*buffer = '\0';

	return (count);
}
