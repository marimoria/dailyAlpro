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

char* trim(char* str) {
  if (!str) return NULL;
  if (!*str) return str;

  char *ptr = str + strlen(str) - 1;
  while(ptr >= str && isspace(*ptr)) {
    ptr--;
  }
  ptr[1] = '\0';

  ptr = str;
  while(isspace(*ptr)) {
    ptr++;
  }

  return ptr;
}

struct dict {
  char kata[250];
  int jumlah;
  int hal[50];
};

typedef struct dict DICT;

int main() {
  int n;
  scanf("%d", &n);
  getchar();

  DICT *daftarDict = (DICT*) malloc(n * sizeof(DICT));

  for (int i = 0; i < n; i++) {
    char *line = trim(getln());
    char *token = strtok(line, ";");
    int indexToken = 0;
    int indexHal = 0;

    while (token != NULL) {
      if (indexToken == 0) {
        strcpy(daftarDict[i].kata, token);
        indexToken++;
      } else {
        daftarDict[i].hal[indexHal] = atoi(token);
        indexHal++;
      }
      token = strtok(NULL, ";");
    }

    daftarDict[i].jumlah = indexHal;
  }

  for (int i = 0; i < n; i++) {
    printf("%s(%d):", daftarDict[i].kata, daftarDict[i].jumlah);

    for (int j = 0; j < daftarDict[i].jumlah; j++) {
      printf("%d", daftarDict[i].hal[j]);

      if (j != (daftarDict[i].jumlah - 1)) {
        printf("->");
      }
    }

    printf("\n");
  }
}