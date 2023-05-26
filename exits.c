#include "shell.h"

/**
 **_strncpy - clones a strng
 *@dest: destination string to be cloned to.
 *@src: source of string
 *@n: characters to be copied.
 *Return: concatenated strings.
 */
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
 **_strncat -  concatenates two strings
 *@dest: string one
 *@src: string two
 *@n: bytes to be used on Max
 *Return: Concatenated stringS
 */
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
 **_strchr - Locate char in stringS.
 *@s:  Parsed string
 *@c: Search char.
 *Return: (s) points to memory area s
 */
char *_strchr(char *s, char c)
{
do
if (*s == c)
return (s);
while (*s++ != '\0');
return (NULL);
}
