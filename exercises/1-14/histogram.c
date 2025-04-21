#include <stdio.h>

#define ASCII 128

int main() {
  int c;
  int i, j;
  int nchars[ASCII];   

  for (i = 0; i < ASCII; ++i) {
    nchars[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++nchars[c];
  }

  for (i = 0; i < ASCII; ++i) {
    if (nchars[i] > 0) {
      if (i == ' ')
        printf("' '   ");
      else if (i == '\n')
        printf("'\\n'  ");
      else if (i == '\t')
        printf("'\\t'  ");
      else
        printf("'%c'   ", i);

      for (j = 0; j < nchars[i]; ++j) {
        putchar('#');
      }
      putchar('\n');
    }
  }
}

