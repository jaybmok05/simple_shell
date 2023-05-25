#include "myshell.h"

/**
 * own_getline - a function that reads input from a
 * file stream or standard input (stdin)
 * @lineptr: holds the address of the buffer
 * @n: holds the address of the first size of the buffer
 * @stream: the stream get input from
 * Return: the number of characters read from
 * the input stream (stdin)
 */

ssize_t own_getline(char **lineptr, size_t *n, FILE *stream)
{
	int read_op;/*read_operation*/
	static ssize_t input;
	ssize_t ret_val;/*returned value*/
	char *buffer, *new_buffer, chars_read = 'z';

	switch (input)
	{
	case 0:
		fflush(stream);
		break;
	default:
		return (-1);
	}
	input = 0;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == 0)
	{
		return (-1);
	}

	do {
		read_op = read(STDIN_FILENO, &chars_read, 1);
		switch (read_op)
		{
		/* Error while reading */
		case -1:
			free(buffer);
			return (-1);
		/* End of file or empty input */
		case 0:
			if (input == 0)
			{
				free(buffer);
				return (-1);
			}
			else
			{
				input++;
				break;
			}
		/* Valid input character */
		default:
			if (input >= BUFFER_SIZE)
			{
				new_buffer = _realloc(buffer, input, input + 1);
				if (new_buffer == NULL)
				{
					free(buffer);
					return (-1);
				}
				buffer = new_buffer;
			}
			buffer[input] = chars_read;
			input++;
			break;
		}
	} while (chars_read != '\n');

	buffer[input] = '\0';
	assign_chars(lineptr, n, buffer, input);
	ret_val = input;

	if (read_op != 0)
	{
		input = 0;
	}
	return (ret_val);
}

/**
 * assign_chars - assigns the line of chars to lineptr for get_line
 * @lineptr: pointer that store the input str
 * @buffer: str that is been called to line
 * @line_s: size of line
 * @buf_size: size of buffer
 */

void assign_chars(char **lineptr, size_t *line_s, char *buffer,
size_t buf_size)
{
	switch (*lineptr != NULL)
	{
	/*lineptr is NULL, indicating an empty buffer */
	case 0:
		if (buf_size > BUFFER_SIZE)
		{
			*line_s = BUFFER_SIZE;
		}
		else
		{
			*line_s = BUFFER_SIZE;
		}
		*lineptr = buffer;
		break;
	/* lineptr is not NULL, buffer already contains a line */
	default:
		switch (*line_s < buf_size)
		{
		/*existing buffer is not large enough to hold the new line */
		case 1:
			if (buf_size > BUFFER_SIZE)
			{
				*line_s = buf_size;
			}
			else
			{
				*line_s = BUFFER_SIZE;
			}
			*lineptr = buffer;
			break;
		/* The existing buffer is large enough */
		default:
			_strcpy(*lineptr, buffer);
			free(buffer);
			break;
		}
		break;
	}
}
