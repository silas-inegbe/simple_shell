#include "shell.h"

/**
 * output - decide what to do with @args
 *
 * @args: array of argument strings
 *
 * Return: void
 */
void output(char **args)
{
	if (args[0][0] == '/')
		execute(args);
	else
	{
		args = check_path(args);
		if (args != NULL)
			execute(args);
	}
}

/**
 * execute - execute a program
 *
 * @args: array of argument strings
 *
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		_exit(99);
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("Error");
		free(args);
		_exit(1);
	}
	else
		wait(&status);
}
