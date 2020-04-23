#include "menger.h"

/**
 * menger - draws 2-D menger square
 * @level: menger square has side legnth 3^level
 */
void menger(int level)
{
	int n, i, j, x, y, c;

	n = pow(3, level);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; )
		{
			x = i;
			y = j++;
			c = '#';
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					c = ' ';
				x /= 3;
				y /= 3;
			}
			putchar(c);
		}
		putchar('\n');
	}
}
