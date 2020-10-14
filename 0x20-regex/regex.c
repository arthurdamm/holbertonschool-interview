#include "regex.h"

/**
 * regex_match - matches regex pattern to string
 * @str: the string
 * @pattern: the pattern
 * Return: 1 if match else 0
 */
int regex_match(char const *str, char const *pattern)
{
	size_t i = 0, sz;
	int **memo = malloc((strlen(str) + 1) * sizeof(int *)), ret;

	for (sz = strlen(pattern) + 1; i < strlen(str) + 1; i++)
	{
		memo[i] = malloc(sz * sizeof(int));
		memset(memo[i], 0, sz * sizeof(int));
	}
	ret = _regex_match(str, pattern, memo, str, pattern);
	for (i = 0; i < strlen(str) + 1; i++)
		free(memo[i]);
	free(memo);
	return (ret);
}

/**
 * _regex_match - matches regex pattern to string
 * @str: the string
 * @pattern: the pattern
 * @memo: memoization grid
 * @s: starting pointer of str
 * @p: starting pointer of pattern
 * Return: 1 if match else 0
 */
int _regex_match(char const *str, char const *pattern, int **memo,
	char const *s, char const *p)
{
	if (memo[str - s][pattern - p])
		return (0);
	memo[str - s][pattern - p] = 1;
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
