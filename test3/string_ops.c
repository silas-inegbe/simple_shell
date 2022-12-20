#include "shell.h"

/**
 * _strlen - return the length of a string
 *
 * @s: string whose length to return
 *
 * Return: length of @s
 */
int _strlen(char *s)
{
	int m;

	m = 0;
	while (s[m] != '\0')
		m++;
	return (m);
}

/**
 * _strdup - return a pointer to a duplicate string of @str
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicate string; NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *a;
	int i, size;


	if (str == NULL)
		return (NULL);
	size = _strlen(str);
	a = smart_alloc((size + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		a[i] = str[i];
	}
	a[i] = str[i];
	return (a);
}

/**
 * _strspn - get the length of a prefix substring
 *
 * @s: string to search
 * @accept: substring to compare string with
 *
 * Return: number of bytes in th initial segment of @s which consist of only
 * bytes from @accept
 */
int _strspn(char *s, const char *accept)
{
	int i, j, flag, count;

	i = flag = count = 0;
	while (s[i] && count == i)
	{
		for (j = 0; accept[j] && !flag; j++)
		{
			if (accept[j] == s[i])
			{
				count++;
				flag = 1;
			}
		}
		flag = 0;
		i++;
	}
	return (count);
}

/**
 * _strchr - locate a character in a string
 *
 * @s: pointer to string
 * @c: character
 *
 * Return: pointer to first occurrence of @c in @s
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		if (s[i] == c)
			return (s + i);
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

/**
 * _strpbrk - search string @s for the first occurance of any bytes of @accept
 *
 * @s: string to search
 * @accept: string to search @s for bytes from
 *
 * Return: a pointer to the byte @s that matches one of the bytes in accept,
 * otherwise NULL
 */
char *_strpbrk(char *s, const char *accept)
{
	int i, j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (accept[j] == s[i])
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
