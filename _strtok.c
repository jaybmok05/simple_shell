#include "myshell.h"

/**
 * _strtok - a function that tokenizes a string
 * @str: the string to tokernize
 * @delim: delimeter used to separate the string
 * Return: returns the tokenizied string
 */

/*Main tokenize function*/
char *_strtok(char str[], const char *delim)
{
	bool token_found;
	static char *curr_token, *str_end;
	char *token_start;
	unsigned int str_len;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
		{
			return (NULL);
		}
		curr_token = str; /*Store first address*/
		str_len = strlen(str);
		str_end = &str[str_len]; /*Store last address*/
	}

	token_start = curr_token;
	
	if (token_start == str_end) /*Reaching the end*/
		return (NULL);

	for (token_found = false; *curr_token; curr_token++)
	{
		/*Breaking loop finding the next token*/
		if (curr_token != token_start)
		{
			if (*curr_token && *(curr_token - 1) == '\0')
				break;
		}
		/*Replacing delimiter for null char*/
		if (is_delimiter(*curr_token, delim))
		{
			*curr_token = '\0';
			if (curr_token == token_start)
				token_start++;
		}
		if (!token_found && *curr_token) /*Str != Delim*/
				token_found = true;
	}
	/*Str == Delim*/
	if (!token_found)
	{
		return (NULL);
	}

	return (token_start);
}


/**
 * is_delimeter - a helper function to check if a character is
 * a delimeter.
 * @c: the character to check against a delimeter
 * @delim: the delimter
 * Return: returns treu if match, false if not
 */

/*Helper function to check if a character is a delimiter*/
bool is_delimiter(char c, const char *delim)
{
	do {
		if (c == *delim)
		{
			return (true);
		}
		delim++;
	} while (*delim);

	return (false);
}
