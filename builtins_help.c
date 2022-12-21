#include "shell.h"

/**
 * help_exit - Print out the description of exit builtin
 */
void help_exit(void)
{
	_puts("exit: exit [status]");
	_puts("    Kill the current running process.\n\n");
	_puts("    Kills the current running process. If \'status\' is ");
	_puts("given then return status to parent process.\n\n");
	_puts("    Arguments:\n");
	_puts("       status   The status to exit with\n\n");
	_puts("    Exit Status:\n");
	_puts("    Returns failure if invalid \'status\' is given otherwise");
	_puts(" returns exit status\n");
}

/**
 * help_unsetenv - Print out the description of unsetenv builtin
 */
void help_unsetenv(void)
{
	_puts("unsetenv: unsetenv [variable]\n");
	_puts("    Remove a variable from the environment.\n\n");
	_puts("    Arguments:\n");
	_puts("       variable   The name of the variable to remove.\n\n");
	_puts("    Exit status:\n");
	_puts("    Return success unless cannot remove variable or variable");
	_puts(" does not exist.\n");
}

/**
 * help_setenv - Print out the description of setenv builtin
 */
void help_setenv(void)
{
	_puts("setenv: setenv [variable] [value]\n");
	_puts("    Change the value of an environment variable.");
	_puts(" If the environment variable does not exist create");
	_puts(" a new variable with the given value.\n\n");
	_puts("    Arguments:\n");
	_puts("       variable   The name of the variable to change or create\n");
	_puts("       value      The value to assign to the variable\n\n");
	_puts("    Exit Status:\n");
	_puts("    Return success unless variable can't be changed or created\n");
}

/**
 * help_env - Print out the description of env builtin
 */
void help_env(void)
{
	_puts("env:\n");
	_puts("    Prints out all environment variables. One");
	_puts(" variable per line.\n\n");
	_puts("    Exit Status:\n");
	_puts("    Return success unless arguments are attempted to be");
	_puts(" passed\n");
}

/**
 * help_help - Print out the description of help builtin
 */
void help_help(void)
{
	_puts("Help: help [name ...]\n");
	_puts("    Display info about builtins\n\n");
	_puts("    Gives brief descriptions of builtins.");
	_puts(" If \'name\' is specified gives more details about all");
	_puts(" commands matching \'name\'\n\n");
	_puts("    Arguments:\n");
	_puts("       name    The name of builtin to get help with\n\n");
	_puts("    Exit status:\n");
	_puts("    Returns success unless invalide \'name\' is given.\n");
}
