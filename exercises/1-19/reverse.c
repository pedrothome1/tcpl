#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[]) {
  int i, j;
  int len;
  int aux;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  len = i;

  for (i = 0, j = len-1; i < j; ++i, --j) {
    aux = s[i]; 
    s[i] = s[j];
    s[j] = aux;
  }
}

