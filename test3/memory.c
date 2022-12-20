#include "shell.h"

/**
 * smart_alloc - Allocate space if there is any, and add memory
 * to list of space to free
 * @size: size of space to allocate
 *
 * Return: pointer to space in memory
 */
void *smart_alloc(size_t size)
{
	void *prt;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		_puts("Not enough memory\n");
		exit(20);
	}
	return (ptr);
}

/**
 * free_array - Frees a pointer array of strings
 * @array: array
 *
 * Return: void
 */
void free_array(char **array)
{
	free(array[0]);
	free(array);
}
