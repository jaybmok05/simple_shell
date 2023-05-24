#include "myshell.h"

/**
  * _realloc - a function that reallocates a
  * memory block using malloc and free
  * Return: pointer to new mem block.
  * @ptr: 1st parameter is a pointer to the memory
  * previously allocated
  * @old_size: 2nd parameter size in bytes allocated for ptr.
  * @new_size: 3rd parameter size in bytes of new memory block.
  */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_alloc;
	unsigned int index;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_alloc = malloc(new_size);
		if (new_alloc == NULL)
		{
			return (NULL);
		}
	}
	if (new_size > old_size && (ptr != NULL))
	{
		new_alloc = malloc(new_size);
		if (new_alloc == NULL)
		{
			return (new_alloc);
		}
		for (index = 0; index < old_size; index++)
		{
			new_alloc[index] = *((char *)ptr + 1);
		}
		free(ptr);
	}
	return (new_alloc);
}

/**
 * mem_cpy - a function that copies memory area.
 * Return: returns pointer dest
 * @destination: 1st parameter
 * @source: 2nd parameter
 * @size: 3rd parameter
 */

void mem_cpy(void *destination, const void *source, unsigned int size)
{
	char *dest = (char *)destination;
	const char *src = (const char *)source;
	unsigned int index = 0;

	while (index < size)
	{
		dest[index] = src[index];
		index++;
	}
}
