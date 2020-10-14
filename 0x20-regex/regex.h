#ifndef REGEX_H
#define REGEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int regex_match(char const *str, char const *pattern);
int _regex_match(char const *str, char const *pattern, int **memo,
	char const *s, char const *p);

#endif

