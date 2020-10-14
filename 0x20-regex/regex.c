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
		return (!*pattern ||
			(pattern[1] == '*' && regex_match(str, pattern + 2)));
	if (pattern[1] == '*')
	{
		if (pattern[0] == '.' || str[0] == pattern[0])
			return (regex_match(str + 1, pattern) ||
				regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	return ((pattern[0] == '.' || pattern[0] == str[0]) &&
		regex_match(str + 1, pattern + 1));
}
