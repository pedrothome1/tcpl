#include <stdio.h>

/*
 *
 * Testing
 * testing
 */

/***
 *
 * Testing
 * testing
 ***/

/* sadfsadfs */
/****/
/***sadfsd */
/***sadfsd *****/
/* **** */
/* // */
/* / */

int main() {
	int c;
	int prev;

	prev = -1;

	while ((c = getchar()) != EOF) {
		if (c == '/') {
			prev = c;
			c = getchar();
			if (c == '*') {
				while (c /* inside code */ == '*') {
					prev = c;
					c = getchar();
				}

				while (!(prev == '*' && c == '/') && c != EOF) {
					prev = c;
					c = getchar();
				}
			} else {
				putchar(/*inside code*/prev);

				if (c != EOF)
					putchar(c);
			}
		} else if (c == '"') {
			putchar(c);
			while ((c = getchar()) != '"')
				putchar(c);
			if (c != EOF)
				putchar(c);
		} else if (c == '\'') {
			putchar(c);
			while ((c = getchar()) != '\'')
				putchar(c);
			if (c != EOF)
				putchar(c);
		} else {
			putchar(c);
		}
	}

	return 0;
}
