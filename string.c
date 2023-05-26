#include "shell.h"

/**
 * _strlen - Return length of string measred.
 * @s: Strng whose length to check ON.
 *
 * Return: int length of the strng to check.
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}

/**
 * _strcmp - Does lexicogarphic parallel compare for two strngs.
 * @s1: First strIng.
 * @s2: Second String.
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Check start of needles via haystack.
 * @haystack: Strng to be searched.
 * @needle: Substring to be found.
 *
 * Return: AddrSs for next charA haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - cCncatenates the two strings haystac.
 * @dest: Destination OF the buFfer.
 * @src: Source oF ThE  buffer.
 *
 * Return: points to destination buffer.
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
