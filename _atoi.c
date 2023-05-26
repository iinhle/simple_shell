#include "shell.h"

/**
 * interactive - return true if shell is in the interactive mode.
 * @info: struct adress form
 *
 * Return: 1 if interactive mode, 0 otherwise.
 */

int interactive(info_t *info)
{return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if char is delimeter.
 * @c: the character to be checked.
 * @delim: delimeter strings.
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * _isalpha - check alphabetic char.
 * @c: character to insert in.
 * Return: 1 if c is alphabetic, 0 otherwise.
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - changes strings to integers.
 * @s: strings to be changed.
 * Return: 0 if no numbers in strings, changed numbers otherwise.
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}


