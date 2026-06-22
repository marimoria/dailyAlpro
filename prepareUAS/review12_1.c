# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

char* trim(char* str) {
  if (!str) return NULL;
  if (!*str) return str;

  char *ptr = str + (strlen(str) - 1);
  while (ptr >= str && isspace(*ptr)) {
    ptr--;
  }
  ptr[1] = '\0';

  ptr = str;
  while (isspace(*ptr)) {
    ptr++;
  }

  return ptr;
}

char* getln() {
  int c;
  int i = 0;

  char *str = (char*) malloc(sizeof(char));

  while (1) {
    c = getchar();

    if (c == EOF || c == '\n') {
      break;
    }

    str = (char*) realloc(str, (i+2) * sizeof(char));
    str[i] = c;
    i++;
  }
  str[i] = '\0';

  if (c == EOF && i == 0) {
    return NULL;
  }

  return str;
}

int main() {
  int alphabet[21] = {0};
  int c, index;
  char *input = trim(getln());

  for (int i = 0; i < strlen(input); i++) {
    c = input[i];

    if (isalnum(c)) {
      index = tolower(c) - 'a';
      alphabet[index]++;
    }
  }

  for (int i = 0; i < 21; i++) {
    if (alphabet[i] != 0) {
      char ch = 'a' + i;
      printf("%c %d\n", ch, alphabet[i]);
    }
  }
  return 0;
}