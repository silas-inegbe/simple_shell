#include "shell.h"

/**
 * main - initialization of shell
 *
 * @ac: argument count
 * @av: array of arguments
 * @env: environment
 *
 * Return: 0 if success, -1 if failure
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	(void)av;
	loop();
	return (0);
}

/**
 * loop - shell prompt loop
 *
 * Return: void
 */
void loop(void)
{
	char *input, **args, *firstarg;
	int looped;
	size_t size;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	size = 0;
	looped = 0;
	input = NULL;
	while (1)
	{
		inchild = 0;
		_puts("Hosh$ ");
		if (getline(&input, &size, stdin) != -1)
		{
			if (input[0] != '\n' && input[0] != '#')
			{
				args = make_args(input);
				firstarg = args[0];
				if (check_builtins(args, input) == -1)
				{
					inchild = 1;
					output(args);
				}
				if (check_arg(firstarg, args[0]) == 0)
					free(args);
				else
					free_array(args);
				looped++;
			}
		}
		else
		{
			free(input);
			_putchar('\n');
			_exit(0);
		}
	}
}

/**
 * sighandler - Print out the prompt if ctrl-C is hit
 * @sig_num: Unused variable necessary for sighandler function types
 */
void sighandler(int sig_num)
{
	(void)sig_num;
	if (inchild == 0)
		_puts("\nHosh$ ");
	signal(SIGINT, sighandler);
}
