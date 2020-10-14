#include "regex.h"

/**
 * regex_match - matches regex pattern to string
 * @str: the string
 * @pattern: the pattern
 * Return: 1 if match else 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str)
	{
		if (!*pattern)
			return (1);
		if (pattern[1] == '*')
			return (regex_match(str, pattern + 2));
		if (pattern[0] == '.')
			return (regex_match(str, pattern + 1));
		return (0);
	}
	if (pattern[1] == '*')
	{
		if (pattern[0] == '.')
			return (regex_match(str + 1, pattern) ||
				regex_match(str, pattern + 2));
		if (str[0] == pattern[0])
			return (regex_match(str + 1, pattern) ||
				regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	if (pattern[0] == '.' || pattern[0] == str[0])
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
