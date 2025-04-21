#include <stdio.h>

int main() {
  int c, nb, nt, nl;

  nb = 0;
  nt = 0;
  nl = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++nb;
    if (c == '\t')
      ++nt;
    if (c == '\n')
      ++nl;
  }

  printf("blanks: %d\n", nb);
  printf("tabs: %d\n", nt);
  printf("newlines: %d\n", nl);
}
