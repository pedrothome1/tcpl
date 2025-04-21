#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
  int i;
  int len;
  int start, end;
  char line[MAXLINE];
  char filtered[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    for (i = 0; i < len-1 && (line[i] == ' ' || line[i] == '\t'); ++i)
      ;
    start = i;

    for (i = len-2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i)
      ;
    end = i;

    for (i = start; i <= end; ++i) {
      filtered[i-start] = line[i];
    }
    filtered[i-start] = '\n';
    filtered[i-start+1] = '\0';

    if (i-start+1 > 1)
      printf("%s", filtered);
  }

  return 0;
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

