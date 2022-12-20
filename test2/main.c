#include "shell.h"
/**
 *  main - Entry point for shell, handles args to shell
 *  @ac: Arg count
 *  @av: Array of args
 *  @env: Environment
 *  Return: 0;
 */
int main(int ac, char **av, char **env)
{
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
	shell(ac, av, env);
	return (0);
}
