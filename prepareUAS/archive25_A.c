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
  while (isspace(*ptr)) {
    ptr++;
  }

  return ptr;
}

char* lowerstr(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

int main() {
  char *target = getln();
  char *line;
  int jumlah = 0;

  while ((line = getln()) != NULL) {
    char *token = strtok(line, " ");

    while (token != NULL) {
      if (strcmp(target, lowerstr(token)) == 0) {
        jumlah++;
      }
      token = strtok(NULL, " ");
    }
  }

  printf("%d\n", jumlah);
  return 0;
}