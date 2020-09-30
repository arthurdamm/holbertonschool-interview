#include "holberton.h"

/**
 * wildcmp - compares two strings using wildcard, recursively
 * @s1: the haystack string, to be searched
 * @s2: the need string, to be found
 * Return: 1 if found else 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
