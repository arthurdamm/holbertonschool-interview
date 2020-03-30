#include "palindrome.h"

static unsigned long _n;

/**
 * is_palindrome - determines if ulong is palindrome
 * @n: the ulong to check
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
	return (((!_n ? _n = n : 0), !n) || (is_palindrome(n / 10)
		&& (n % 10 == _n % 10) ? (_n /= 10), 1 : 0));
}
