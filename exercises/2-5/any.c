#include <stdio.h>

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
			;
		if (s2[j] != '\0')
			return i;
	}
	return -1;
}

int main(void)
{
	char s[] = "pedro";
	char cs[] = "iou";
	int pos = any(s, cs);

	printf("any(\"%s\", \"%s\")\n", s, cs);
	printf("  pos = %d\n", pos);
	if (pos != -1)
		printf("  ch  = %c\n", s[pos]);

	return 0;
}
