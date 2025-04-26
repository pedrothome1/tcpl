#include <stdio.h>

/* 
 * x = 00101100 == 44 
 * getbits(x, 4, 3) == 00000011 == 3
 *
 * (x >> (p+1-n)) == 00001011
 */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) /* move the field to the right end of the word */
		&
		~(~0 << n) /* mask the field bits, so only the field is considered */;
}

int main(void)
{
	printf("%d should equal 3\n", getbits(44, 4, 3));

	return 0;
}
