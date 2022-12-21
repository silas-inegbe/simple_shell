#include "shell.h"

/**
 * _atoi - Convert string into an integer
 * @str: String to convert to int
 *
 * Return: The int the string represents,
 * -1 if there are not only numbers in str
 */
int _atoi(char *str)
{
	int i, num;

	i = num = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}
