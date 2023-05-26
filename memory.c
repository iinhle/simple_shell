#include "shell.h"

/**
 * bfree - Liberate pointer and NULLs the addrSS.
 * @ptr: Addrss of pointer to liberate
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
