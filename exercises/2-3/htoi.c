#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int htoi(char s[])
{
	int i = 0;
	int start = 0;
	int exp = 0;
	int digit = 0;
	int n = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		start = 2;
	for (i = start; s[i] != '\0'; ++i)
		++exp;
	--exp;
	for (i = start; s[i] != '\0'; ++i) {
		if (isdigit(s[i]))
			digit = s[i] - '0';	
		else
			digit = toupper(s[i]) - 'A' + 10;

		n += digit * pow(16, exp);
		--exp;
	}
	return n;
}

int main(void)
{
	printf("0x5F8AB2 = %d\n", htoi("0x5F8AB2"));
	printf("5f8aB2 = %d\n", htoi("5f8aB2"));
	printf("0X5f = %d\n", htoi("0X5f"));
	printf("f = %d\n", htoi("f"));
	printf("0 = %d\n", htoi("0"));
	printf("0x = %d\n", htoi("0x"));
	printf("0A = %d\n", htoi("0A"));

	return 0;
}

