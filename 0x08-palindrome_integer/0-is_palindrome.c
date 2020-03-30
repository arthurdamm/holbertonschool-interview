#include "palindrome.h"

/**
 * is_palindrome_recursive - determines if ulong is palindrome
 * @n: the right-shifted digits of ulong to check
 * @_n: address of copy of ulong to check against in reverse
 * Return: 1 if palindrome else 0
 */
int is_palindrome_recursive(unsigned long n, unsigned long *_n)
{
	return (!n || (is_palindrome_recursive(n / 10, _n)
		 && (n % 10 == *_n % 10) ? (*_n /= 10), 1 : 0));
}

/**
 * is_palindrome - determines if ulong is palindrome
 * @n: the ulong to check
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
	return (is_palindrome_recursive(n, &n));
}
