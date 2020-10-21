#include "substring.h"

typedef struct Trie {
	struct Trie *children[26];
	int word;
	int count;
	int left;
	char *val;
} Trie;

#define INDEX(x) ((x) - 'a')

void free_trie(Trie *root)
{
	int i = 0;

	for (i = 0; i < 26; i++)
		if (root->children[i])
			free_trie(root->children[i]);
	free(root);
}

int search_tree(Trie *node, char *str, int k)
{
	char c = str[k];
	str[k] = 0;
/* 	printf("SEARCHING:[%s]\n", str); */
	str[k] = c;
	for (; k; str++, k--) {
		if (!node->children[INDEX(*str)])
			return (0);
		node = node->children[INDEX(*str)];
	}

	if (node->left-- > 0) {
/* 		printf("FOUND: [%s]\n", node->val); */
		return (1);
	}
	return (0);
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
	int i = 0, j, k, slen, matches;
	Trie *root, *node, **nodes;
	char const *str;
	int *indices;

	*n = 0;
	indices = calloc(1000, sizeof(int));
	root = calloc(1, sizeof(Trie));
	nodes = calloc(1, sizeof(*nodes) * nb_words);

	setbuf(stdout, NULL);

	for (i = 0; i < nb_words; i++) {
/* 		printf("[%d] [%s]\n", i, words[i]); */
		node = root;
		for (str = words[i]; *str; str++) {
			if (!node->children[*str - 'a'])
				node->children[*str - 'a'] = calloc(1, sizeof(Trie));
			node = node->children[*str - 'a'];
		}
		node->word = 1;
		node->count++;
		node->left++;
		node->val = (char *)words[i];
		nodes[i] = node;
	}
	
	slen = strlen(s);
	k = strlen(words[0]);
/* 	printf("K: [%d]\n", k); */

	for (i = 0; i < slen; i++) {
		matches = 0;
/* 		printf("CHECKING AT i:[%d]\n", i); */
		for (j = i; j <= slen - k; j += k) {
			if (search_tree(root, (char *)s + j, k))
			{
				if (++matches == nb_words) {
 					/* printf("ANSWER! [%d] %d\n", i, *n); */
 					indices[*n] = i;
 					*n += 1;
					break;
				}
/* 				printf("MATCHES AT: [%d]\n", matches); */
			}
			else {
/* 				printf("MATCH FAILED\n"); */
				break;
			}
		}
/* 		printf("\nRESET:\n"); */
		for (j = 0; j < nb_words; j++) {
			nodes[j]->left = nodes[j]->count;
/* 			printf("[%s] (%d)\n", nodes[j]->val, nodes[j]->count); */
		}
	}


	free_trie(root);
	free(nodes);
	return (indices);
	(void)s;
	(void)words;
	(void)nb_words;
}

