#include <stdio.h>

#define TEST(b) ((b) ? "PASS" : "FAIL")

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (y & ~(~0 << n)) << (p-n+1) | (x & ~(~(~0 << n)) << (p-n+1));
}

int main(void)
{
	/*
	 * x = 00110100; p = 4; n = 3; y = 00000010
	 * x		== 52
	 * y		== 2
	 * expected == 40
	 * expected = 00101000
	 */

	int x = 52;
	int y = 2;
	int expected = setbits(x, 4, 3, y);

	printf("%s\t%u should be 40\n", TEST(expected == 40), expected);

	return 0;
}
