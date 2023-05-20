#include "myshell.h"

/**
 * _strcpy - copies src sting with its null byte to dest
 * @src: string to copy
 * @dest: string to append src to
 * Return: pointer to newly formed string
 */

char *_strcpy(char *dest, char *src)
{
	char *result = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}
