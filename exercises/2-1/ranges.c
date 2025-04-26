#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("signed char\n");
	printf("  min: %d\n", CHAR_MIN);
	printf("  max: %d\n", CHAR_MAX);
	printf("unsigned char\n");
	printf("  min: %u\n", 0);
	printf("  max: %u\n", UCHAR_MAX);
	printf("signed short\n");
	printf("  min: %d\n", SHRT_MIN);
	printf("  max: %d\n", SHRT_MAX);
	printf("unsigned short\n");
	printf("  min: %u\n", 0);
	printf("  max: %u\n", USHRT_MAX);
	printf("signed int\n");
	printf("  min: %d\n", INT_MIN);
	printf("  max: %d\n", INT_MAX);
	printf("unsigned int\n");
	printf("  min: %u\n", 0);
	printf("  max: %u\n", UINT_MAX);
	printf("signed long\n");
	printf("  min: %ld\n", LONG_MIN);
	printf("  max: %ld\n", LONG_MAX);
	printf("unsigned long\n");
	printf("  min: %lu\n", 0UL);
	printf("  max: %lu\n", ULONG_MAX);
	printf("float\n");
	printf("  min: %f\n", -FLT_MAX);
	printf("  max: %f\n", FLT_MAX);
	printf("double\n");
	printf("  min: %lf\n", -DBL_MAX);
	printf("  max: %lf\n", DBL_MAX);
	printf("long double\n");
	printf("  min: %Lf\n", -LDBL_MAX);
	printf("  max: %Lf\n", LDBL_MAX);
}
