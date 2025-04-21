#include <stdio.h>

#define TABSTOP 8

int main() {
  int c, i;
  int len;
  int nblanks;

  len = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      nblanks = TABSTOP - len % TABSTOP;
      for (i = 0; i < nblanks; ++i)
        putchar(' ');
      len += nblanks;
    } else if (c == '\n') {
      putchar(c); 
      len = 0;
    } else {
      putchar(c);
      ++len;
    }
  }
}

