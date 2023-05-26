#include "shell.h"

/**
 * _myenv - print current environment.
 * @info: Struct contains potetial arguments. To maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - get value of environemtal variables in.
 * @info: Struct contains potetial arguments. too maintain
 * @name: environment variable names.
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *b;
while (node)
{
b = starts_with(node->str, name);
if (b && *b)
return (b);
node = node->next;
}
return (NULL);
}

/**
 * _mysetenv - Init new envir variable,
 *  or enhance existing one.
 * @info: Struct contains pottial arguments to maintain
 * const funct prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - Delete an envir var.
 * @info: Struct contains potetial arguments to maintain
 * const funct prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
int i;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);
return (0);
}

/**
 * populate_env_list - floods env linked lists.
 * @info: Struct contains potetial arguments to maintain
 *  const funct prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
