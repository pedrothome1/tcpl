#include <stdio.h>

int main() {
  int c;
  int i;
  int len;

  len = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (len > 0) {
        for (i = 0; i < 20 - len; ++i)
          putchar(' ');

        for (i = 0; i < len; ++i)
          putchar('#');

        putchar('\n');

        len = 0;
      }
    } else {
      putchar(c);
      ++len;
    }
  }
}
