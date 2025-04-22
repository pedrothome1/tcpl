#include <stdio.h>

int main() {
    int c, next;
    int in_block_comment = 0;
    int in_line_comment = 0;
    int in_string = 0;
    int in_char = 0;

    while ((c = getchar()) != EOF) {
        if (in_block_comment) {
            if (c == '*') {
                next = getchar();
                if (next == '/') {
                    in_block_comment = 0;
                } else if (next != EOF) {
                    ungetc(next, stdin);
                } else {
                    break;
                }
            }
            continue;
        }

        if (in_line_comment) {
            if (c == '\n') {
                in_line_comment = 0;
                putchar(c);
            }
            continue;
        }

        if (in_string) {
            putchar(c);
            if (c == '\\') {
                c = getchar(); // escape next
                if (c != EOF) putchar(c);
            } else if (c == '"') {
                in_string = 0;
            }
            continue;
        }

        if (in_char) {
            putchar(c);
            if (c == '\\') {
                c = getchar(); // escape next
                if (c != EOF) putchar(c);
            } else if (c == '\'') {
                in_char = 0;
            }
            continue;
        }

        // Start of something?
        if (c == '"') {
            in_string = 1;
            putchar(c);
        } else if (c == '\'') {
            in_char = 1;
            putchar(c);
        } else if (c == '/') {
            next = getchar();
            if (next == '*') {
                in_block_comment = 1;
            } else if (next == '/') {
                in_line_comment = 1;
            } else {
                putchar(c);
                if (next != EOF)
                    ungetc(next, stdin);
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}

