#include <stdio.h>

#define CODE 0
#define BLOCK_COMMENT 1
#define STRING 2
#define CHAR 3
#define ESCAPE_STRING 4
#define ESCAPE_CHAR 5

int main() {
	int c, state = CODE;

	while ((c = getchar()) != EOF) {
		if (state == CODE) {
			if (c == '/') {
				int next = getchar();
				if (next == '*') {
					state = BLOCK_COMMENT;
				} else {
					putchar(c);
					if (next != EOF) ungetc(next, stdin);
				}
			} else if (c == '"') {
				state = STRING;
				putchar(c);
			} else if (c == '\'') {
				state = CHAR;
				putchar(c);
			} else {
				putchar(c);
			}
		} else if (state == BLOCK_COMMENT) {
			if (c == '*') {
				int next = getchar();
				if (next == '/') {
					state = CODE;
				} else if (next != EOF) {
					ungetc(next, stdin);
				}
			}
		} else if (state == STRING) {
			putchar(c);
			if (c == '\\') {
				state = ESCAPE_STRING;
			} else if (c == '"') {
				state = CODE;
			}
		} else if (state == ESCAPE_STRING) {
			putchar(c);
			state = STRING;
		} else if (state == CHAR) {
			putchar(c);
			if (c == '\\') {
				state = ESCAPE_CHAR;
			} else if (c == '\'') {
				state = CODE;
			}
		} else if (state == ESCAPE_CHAR) {
			putchar(c);
			state = CHAR;
		}
	}

	return 0;
}

