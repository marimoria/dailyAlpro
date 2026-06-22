# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

char* getln() {
  int c;
  int i = 0;
  char *str = (char*) malloc(sizeof(char));

  while (1) {
    c = getchar();

    if (c == EOF || c == '\n') {
      break;
    }

    str = (char*) realloc(str, (i + 2) * sizeof(char));
    str[i] = c;
    i++;
  }
  str[i] = '\0';

  if (c == EOF && i == 0) {
    return NULL;
  }

  return str;
}

char* trim(char* str) {
  if (!str) return NULL;
  if (!*str) return str;

  char *ptr = str + strlen(str) - 1;
  while (ptr >= str && isspace(*ptr)) {
    ptr--;
  }
  ptr[1] = '\0';

  ptr = str;
  while(isspace(*ptr)) {
    ptr++;
  }

  return ptr;
}

int main() {
  char *line;
  int c;

  while((line = getln()) != NULL) {
    int newWord = 1; // new line

    for (int i = 0; i < strlen(line); i++) { // each char in line
      c = line[i];

      if (newWord) {
        line[i] = toupper(line[i]);
        newWord = 0;
      } else if (c == ' ' || c == '\t') {
        newWord = 1;
      }
    }

    printf("%s\n", line);
  }

  return 0;
}