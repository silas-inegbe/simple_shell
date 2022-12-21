#include "shell.h"

/**
 * _unsetenv - unset an environment variable
 *
 * @name: name of variable
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *name)
{
	char **ep;
	int len;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	len = _strlen(name);
	ep = environ;
	while (*ep != NULL)
	{
		if (_strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
			while (*ep != NULL)
			{
				*ep = *(ep + 1);
				ep++;
			}
		else
			ep++;
	}
	return (0);
}

/**
 * _findenv - get the pointer to an environment variable
 *
 * @name: variable name
 *
 * Return: pointer to variable if it exists, or NULL if it doesn't
 */
char *_findenv(char *name)
{
	char **envp;
	int len;

	envp = environ;
	len = _strlen(name);
	while (*envp != NULL)
	{
		if (_strncmp(*envp, name, len) == 0)
			return (*envp);
		envp++;
	}
	return (*envp);
}

/**
 * _addenv - add or modify an environment variable
 *
 * @newvar: variable and value
 * @name: name of variable to add or modify
 *
 * Return: 0 if success, -1 if failure
 */
int _addenv(char *newvar, char *name)
{
	char **newenv, **newhead;
	size_t i;

	if (_findenv(name) == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
			;
		newenv = smart_alloc(sizeof(char *) * (i + 2));
		newhead = newenv;
		i = 0;
		while (*environ != NULL)
		{
			*newenv = *environ;
			newenv++;
			environ++;
		}
		*newenv = newvar;
		newenv++;
		*newenv = NULL;
		environ = newhead;
		return (0);
	}
	else
		return (-1);
	return (0);
}
