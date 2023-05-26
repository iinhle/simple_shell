#include "shell.h"

/**
 * _myhistory - shows history list, one commnd by line, followed
 * by line numbers, starting at 0.
 * @info: Struct contains potental arguments. To maintains
 *        constant funct prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - sets all alias to strings.
 * @info: parameter structure.
 * @str: strings alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *b, s;
int ret;
b = _strchr(str, '=');
if (!b)
return (1);
s = *b;
*b = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*b = s;
return (ret);
}

/**
 * set_alias - set all alias to strings
 * @info: paramter structure.
 * @str: strings alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *b;
b = _strchr(str, '=');
if (!b)
return (1);
if (!*++b)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - print alias strings.
 * @node: alias node.
 *
 * Return: Always 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
char *b = NULL, *z = NULL;
if (node)
{
b = _strchr(node->str, '=');
for (z = node->str; z <= b; z++)
_putchar(*z);
_putchar('\'');
_puts(b + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - mimic alias builtin - the man alias
 * @info: Struct contains potetial arguments. Used for maintains.
 * const funct prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
int i = 0;
char *b = NULL;
list_t *node = NULL;
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
b = _strchr(info->argv[i], '=');
if (b)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}
return (0);
}
