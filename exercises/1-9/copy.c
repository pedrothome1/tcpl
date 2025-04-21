#include <stdio.h>

int main() {
  int c;
  int last;

  last = 0;

  while ((c = getchar()) != EOF) {
    if (last != ' ' || c != ' ')
      putchar(c);
    last = c;
  }
}

