#include "shell.h"

/**
 * _memset - Fills memory space with constant Byte.
 * @s: Point to memory area.
 * @b: Byte to fill *s with.
 * @n: Bytes to be filled.
 * Return: (s) points to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffree - Liberates strng of strngs.
 * @pp: Strng of strngs.
 */
void ffree(char **pp)
{
char **a = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 * _realloc - This reallocates block of memory in
 * @ptr: Points to previous mallocated block on memory
 * @old_size: Byte size of previous block.
 * @new_size: Byte size of new block meausre.
 *
 * Return: Points to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
