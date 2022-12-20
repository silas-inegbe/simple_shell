#include "shell.h"

/**
 * hosh_setenv - set an environment variable
 *
 * @args: argument array
 *
 * Return: 0 on success, -1 on failure
 */
int hosh_setenv(char **args)
{
	char *envp;
	int i, j, len;

	if (args[1] == NULL || args[2] == NULL || args[1][0] == '\0')
	{
		_puts("setenv syntax: setenv VARIABLE VALUE\n");
		return (-1);
	}
	_unsetenv(args[1]);
	len = 0;
	for (i = 2; args[i] != NULL; i++)
		for (j = 0; args[i][j] != '\0'; j++, len++)
			;
	envp = smart_alloc(sizeof(char) * (len + i - 1));
	envp = _strcpy(envp, args[1]);
	envp = str_concat(envp, "=");
	for (i = 2; args[i] != NULL; i++)
	{
		envp = str_concat(envp, args[i]);
		if (args[i + 1] != NULL)
			envp = str_concat(envp, " ");
	}
	if (_addenv(envp, args[1]) != 0)
		return (-1);
	return (0);
}

/**
 * hosh_unsetenv - unset an environment variable
 *
 * @args: argument array
 *
 * Return: 0 if success, -1 if failure
 */
int hosh_unsetenv(char **args)
{
	if (args[1] == NULL)
		return (-1);
	return (_unsetenv(args[1]));
}

/**
 * hosh_exit - exit the current child process & free what must be free'd
 * @args: Double pointer to the command and given args
 * @input: The original input from the user
 *
 * Return: 0 if success, 1 if failure
 */
int hosh_exit(char **args, char *input)
{
	int status;

	if (args[1] == NULL)
	{
		free(input);
		free(args);
		_exit(0);
	}
	else
	{
		status = _atoi(args[1]);
		if (status == -1)
		{
			_puts("Illegal number\n");
			return (1);
		}
		free(input);
		free(args);
		_exit(status);
	}
	return (1);
}

/**
 * hosh_printenv - print the list of environment variables
 * @args: Arguments passed to hosh_printenv
 *
 * Return: 0 on success, 1 on failure
 */
int hosh_printenv(char **args)
{
	char c;
	int i, j;

	if (args[1] == NULL)
	{
		for (i = 0; environ[i]; i++)
		{
			for (j = 0; environ[i][j]; j++)
			{
				c = environ[i][j];
				_putchar(c);
			}
			_putchar('\n');
		}
		return (0);
	}
	return (1);
}

/**
 * hosh_help - Print out help for given commands or list all builtins available
 * @args: List of arguments passed to hosh_help
 *
 * Return: 0 on success, 1 on failure
 */
int hosh_help(char **args)
{
	help_t builtins[] = {
		{"exit", help_exit},
		{"setenv", help_setenv},
		{"unsetenv", help_unsetenv},
		{"env", help_env},
		{"help", help_help},
		{NULL, NULL}
	};
	int i, j, arglen, foundhelp;

	foundhelp = 0;
	i = 1;
	if (args[1] == NULL)
	{
		print_help();
		return (0);
	}
	while (args[i] != NULL)
	{
		j = 0;
		while (builtins[j].name != NULL)
		{
			arglen = _strlen(args[i]);
			if (_strncmp(builtins[j].name, args[i], arglen) == 0)
			{
				foundhelp++;
				builtins[j].func();
				break;
			}
			j++;
		}
		i++;
	}
	if (foundhelp > 0)
		return (0);
	_puts("Sorry, Could not find help for that command.\n");
	return (1);
}
