# include <stdio.h>
# include <ctype.h>

int main() {
  char chars[2];
  char ch;

  scanf("%c %c", &chars[0], &chars[1]);
  getchar();

  while ((ch = getchar()) != EOF) {
    int isUpper = isupper(ch);

    if (tolower(ch) == tolower(chars[0])) {
      if (isUpper) {
        printf("%c", toupper(chars[1]));
      } else {
        printf("%c", tolower(chars[1]));
      }
    } else {
      printf("%c", ch);
    }
  }

  return 0;
}