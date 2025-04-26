#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	i = j = k = 0;

	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)	
			;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main(void)
{
	char s[] = "pedro";
	squeeze(s, "aeiou");

	printf("%s\n", s);

	return 0;
}
