#include <stdio.h>

#define TABSTOP 8

int main() {
	int c;
	int i;
	int len;
	int rem;
	int nblanks;

	len = nblanks = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar(c);
			len = 0;
		} else if (c == ' ') {
			++nblanks;
		} else {
			rem = TABSTOP - len % TABSTOP;

			if (nblanks > 0) {
				if (nblanks >= rem) {
					putchar('\t');
					nblanks -= rem;
					len += rem;
				}
				
				for (i = 0; i < nblanks / TABSTOP; ++i) {
					putchar('\t');
					len += TABSTOP;
				}
				for (i = 0; i < nblanks % TABSTOP; ++i) {
					putchar(' ');
					++len;
				}
				
				nblanks = 0;
			}

			if (c == '\t')
				len += rem;
			else
				++len;

			putchar(c);
		}
	}
}

