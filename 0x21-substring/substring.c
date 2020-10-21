#include "substring.h"


int cmp(const void *a, const void *b) {
	return strcmp(a, b);
}

/**
 * find_substring - finds substring composed of all concatenated words
 * @s: the string to search
 * @words: array of contentated words to find
 * @nb_words: the size of passed array
 * @n: size of return array, to set
 * Return: array of indices where all words found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0;

	setbuf(stdout, NULL);
	for (i = 0; i < nb_words; i++)
		printf("[%d] [%s]\n", i, words[i]);
	qsort(words, nb_words, sizeof(char *), cmp);
	for (i = 0; i < nb_words; i++)
		printf("[%d] [%s]\n", i, words[i]);
	printf("<%s>\n", (char *)bsearch(words[2], words, nb_words, strlen(words[0]), cmp));
	*n = 0;
	return (NULL);
	(void)s;
	(void)words;
	(void)nb_words;
}

