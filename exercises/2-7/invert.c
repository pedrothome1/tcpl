#include <stdio.h>

/* 10001010 == 138 */
/* 10010110 == 150 */

/* zero_field: */
/* ~0u					== 11111111 */
/* ~0u << 3				== 11111000 */
/* ~(~0u << 3)			== 00000111 */
/* ~(~0u << 3) << 2		== 00011100 */
/* ~(~(~0u << 3) << 2)	== 11100011 */
unsigned invert(unsigned x, int p, int n)
{
	unsigned zero_field = ~(~(~0u << n) << (p-n+1));
	unsigned inverted = ~x >> (p-n+1);	// *inverted* field at rightmost position
	inverted &= ~(~0 << n);				// unset all bits at the left of the field
	inverted <<= (p-n+1);				// shift field back at its original position
	inverted &= ~0 << (p-n+1);          // unset all bits at the right of the field

	return (x & zero_field) | inverted;
}

int main(void)
{
	unsigned x = 138u;
	int p = 4, n = 3;

	printf("%u\n", invert(x, p, n));

	return 0;
}
