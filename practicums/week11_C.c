#include <stdio.h>
#include <ctype.h>

int main() {
  int ch;
  int newWord = 1;

  while ((ch = getchar()) != EOF) {
    if (ch == ' ' || ch == '\t' || ch == '\n') {
      printf("%c", ch);
      newWord = 1;
    } else if (newWord) {
      printf("%c", toupper(ch));
      newWord = 0;
    } else {
      printf("%c", ch);
    }
  }
  return 0;
}