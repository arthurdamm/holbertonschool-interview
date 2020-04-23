#!/usr/bin/env python3
"""
Prints 2-D Menger Square of side-length 3^N
"""

import sys

def menger(n):
    n = 3**n
    for row in range(n):
        for col in range(n):
            c = "#"
            _row = row
            _col = col
            while _row and _col:
                if _row % 3 == 1 and _col % 3 == 1:
                    c = " "
                _row //= 3
                _col //= 3
            print(c, end="")
        print()

if __name__ == "__main__":
    menger(int(sys.argv[1]))
