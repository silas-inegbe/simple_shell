#include "shell.h"

/**
 * check_builtins - Check to see if given command is a builtin
 * @args: Array holding command and all its arguments
 * @input: The user input received from getline
 *
 * Return: the return value of the builtin called on success,
 * or -1 if it failed
 */
int check_builtins(char **args, char *input)
{
	builtins_t builtins[] = {
		{"exit", hosh_exit},
		{"env", hosh_printenv},
		{"unsetenv", hosh_unsetenv},
		{"setenv", hosh_setenv},
		{"help", hosh_help},
		{NULL, NULL}
	};
	int i, len;

	len = _strlen(args[0]);
	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strncmp(args[0], "exit", 4) == 0)
			return (builtins[0].func(args, input));
		if (_strncmp(args[0], builtins[i].name, len) == 0)
			return (builtins[i].func(args));
	}
	return (-1);
}
