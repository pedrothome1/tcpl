#include <stdio.h>

int main() {
  int c;
  int last;

  last = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (last != ' ' && last != '\n' && last != '\t') {
        putchar('\n');
      }
    } else {
      putchar(c);
    }

    last = c;
  }
}
