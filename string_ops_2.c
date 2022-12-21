#include "shell.h"

/**
 * _strncmp - compare two strings
 *
 * @s1: first string to compare with @s2
 * @s2: second string from which to compare @s1
 * @n: Length of string to compare to
 *
 * Return: integer value of characters of @s1 minus character number of @s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n > 0)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		n--;
	}
	return (c1 - c2);
}

/**
 * str_concat - concatenate two strings into memory space
 *
 * @s1: First string
 * @s2: Second string
 *
 * Return: pointer to combined string
 */
char *str_concat(char *s1, char *s2)
{
	char *s, *p;
	int s1length, s2length;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1length = _strlen(s1);
	s2length = _strlen(s2);
	s = smart_alloc(s1length + s2length + 1);
	p = s;
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (p);
}


/**
 * *_strcpy - copies @src string to @dest buffer, including '\0'
 *
 * @dest: pointer to buffer for string
 * @src: pointer to string to copy to buffer
 *
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	int n;

	n = 0;
	for (n = 0; src[n] != '\0'; n++)
		dest[n] = src[n];
	dest[n] = '\0';
	return (dest);
}
