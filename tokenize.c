#include "shell.h"

/**
 * tokenize - create a token from @input
 *
 * @input: string to tokenize
 * @delim: delimitor string
 * @saveptr: save pointer
 *
 * Return: the next token found in @input string
 */
char *tokenize(char *input, const char *delim, char **saveptr)
{
	char *token;
	int i;

	i = 0;
	if (input == NULL)
		input = *saveptr;
	input += _strspn(input, delim);
	if (*input == '\0')
	{
		*saveptr = input;
		return (NULL);
	}
	token = input;
	input = _strpbrk(input, delim);
	if (input == NULL)
	{
		while (token[i] != '\0')
			i++;
		*saveptr = token + i;
	}
	else
	{
		*input = '\0';
		*saveptr = input + 1;
	}
	return (token);
}
