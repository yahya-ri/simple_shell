#include "main.h"

/**
 * _realloc - reallocate a block of memory
 * @ptr: memory targeted.
 * @old_size: old size of momory.
 * @new_size: size that will be allocated.
 * Return: pointer to the newly created array.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *realoc;
	unsigned int i;

	i = -1;
	if (old_size == new_size)
		return (ptr);
	if (new_size <= 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		realoc = malloc(new_size);
		if (!realoc)
			return (NULL);
	}
	if (new_size > old_size && ptr)
	{
		realoc = malloc(new_size);
		if (!realoc)
			return (NULL);
		while (i < new_size)
		{
			while (++i < old_size)
				((char *)realoc)[i] = ((char *)ptr)[i];
			((char *)realoc)[i] = 0;
		}
		free(ptr);
	}
	return (realoc);
}
