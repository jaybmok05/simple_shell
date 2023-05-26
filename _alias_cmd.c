#include "myshell.h"

int num_aliases = 0;

/**
 * alias - a function for the buitl in command alias
 * @argc: the count of arguments
 * @argv: the arguments
 * Return: returns 0
 */

int alias_cmd(int argc, char* argv[])
{
	char *name, *value;
	int index, index_0;

	if (argc == 1)
	{
		print_aliases();
	}
	else
	{
		if (_strcmp(argv[1], "name") == 0)
		{
			for (index = 2; index < argc; index++)
			{
				for (index_0 = 0; index_0 < num_aliases; index_0++)
				{
					if (_strcmp(aliases[index_0].name, argv[index]) == 0)
					{
						print_alias(aliases[index_0]);
						break;
					}
				}
			}
		}
		else
		{
			index = 0;

			while (index < argc)
			{
				name = _strtok(argv[index], "=");
				value = _strtok(NULL, "=");
				add_alias(name, value);
				index++;
			}
		}
	}

	return (0);
}

/**
 * print_alias - a function that print the alias
 */

void print_alias(alias_t alias)
{
	_printf("%s='%s'\n", alias.name, alias.value);
}

/**
 * print_alias - a function print list of aliases
 */

void print_aliases()
{
	int index = 0;

	while (index < num_aliases)
	{
		print_alias(aliases[index]);
		index++;
	}
}

/**
 * add_alias - a function that combines name and value
 * @name: the name of the alias
 * @value: the value of the alias
 */

void add_alias(char* name, char* value)
{
	int index = 0;

	while (index < num_aliases)
	{
		if (_strcmp(aliases[index].name, name) == 0)
		{
			_strcpy(aliases[index].value, value);
			return;
		}
		index++;
	}

	if (num_aliases < MAX_ALIASES)
	{
		_strcpy(aliases[num_aliases].name, name);
		_strcpy(aliases[num_aliases].value, value);
		num_aliases++;
	}
	else
	{
		_printf("Maximum number of aliases reached.\n");
	}
}
