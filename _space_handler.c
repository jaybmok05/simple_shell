#include "myshell.h"

/**
 * _isspace - handles white spaces in command line
 * @c: any of the whitespace characters
 * Return: non-zero if c is whitespace character, 0 otherwise
 */

int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\r' || c == '\f' ||
			c == '\v');
}
