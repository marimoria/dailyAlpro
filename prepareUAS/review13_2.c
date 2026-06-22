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

char* lowerStr(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

struct kata {
  char kata[250];
  int jumlah;
};

typedef struct kata KATA;

int main() {
  char *line;
  int jumlahKata = 0;
  KATA *daftarKata = (KATA*) malloc(sizeof(KATA));

  while ((line = getln()) != NULL) {
    char *token = strtok(line, " \n\t,.;-\"");

    while (token != NULL) {
      int wordExist = 0;
      int wordExistIndex = 0;

      for (int i = 0; i < jumlahKata; i++) {
        if (strcmp(daftarKata[i].kata, lowerStr(token)) == 0) {
          wordExist = 1;
          wordExistIndex = i;
          break;
        }
      }

      if (wordExist) {
        daftarKata[wordExistIndex].jumlah++;
      } else {
        daftarKata = (KATA*) realloc(daftarKata, (jumlahKata + 1) * sizeof(KATA));
        strcpy(daftarKata[jumlahKata].kata, lowerStr(token));
        daftarKata[jumlahKata].jumlah == 1;
        jumlahKata++;
      }

      token = strtok(NULL, " \n\t,.;-\"");
    }
  }

  for (int i = 0; i < jumlahKata; i++) {
    printf("%s %d\n", daftarKata[i].kata, daftarKata[i].jumlah);
  }

  return 0;
}