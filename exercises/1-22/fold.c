#include <stdio.h>

#define MAXLINE 1000
#define MAXCOLS 50

/*
ORIGINAL:
AAAAA AAAAAAAA AAAAA AA AAAAAAA

WRAPPED:
AAAAA AAAAAAAA AAAAA
AA AAAAAAA
*/

int get_line(char line[], int maxline);

int main() {
	int i, j;
	int len;
	int peek;
	char line[MAXLINE];

	len = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		--len;	/* length without trailing \n */

		while (len > MAXCOLS) {
			for (i = MAXCOLS; i >= 0 && line[i] != ' ' && line[i] != '\t'; --i)
				;

			if (i >= 0) {			/* found a blank/tab to split the line */
				line[i] = '\0';
				printf("%s\n", line);
				len = (len-1)-(i+1)+1;

				for (j = 0; j < len; ++j)
					line[j] = line[(i+1)+j];
			} else {			/* didn't found a blank/tab, split large word */
				i = MAXCOLS;
				peek = line[i];
				line[i] = '\0';
				
				printf("%s\n", line);

				line[i] = peek;
				len = (len-1)-i+1;

				for (j = 0; j < len; ++j)
					line[j] = line[i+j];
			}

			line[j] = '\0';
		}

		printf("%s\n", line);
	}
}

int get_line(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

