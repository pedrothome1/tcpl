#include <stdio.h>

int main(void)
{
    unsigned x = 0x00000001u; // Only the highest bit is set
    unsigned shifted = x >> 3;

    printf("Original: 0x%08X\n", x);
    printf("Shifted : 0x%08X\n", shifted);

    return 0;
}

