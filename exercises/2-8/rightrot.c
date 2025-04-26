#include <stdio.h>

#define WORD unsigned char

int wordlength(void)
{
	int i;
	WORD x = ~0;

	for (i = 0; x > 0; ++i)
		x >>= 1;
	return i;
}

WORD rightrot(WORD x, int n)
{
	int wl = wordlength();

	if (n % wl > 0) {
		WORD lbits = (~(~0u << n) & x) << (wl - n);
		x >>= n;
		x |= lbits;
	}
	return x;	
}

int main(void)
{
	/*
	 * given a word size of 8
	 * rightrot this by 3
	 * 00010110 == 22
	 * gives
	 * 11000010 == 194
	 */

	printf("%u\n", rightrot(22, 3));

	return 0;
}
