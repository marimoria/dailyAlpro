# include <stdio.h>
# include <ctype.h>

int main() {
  int freq[26] = {0};
  int ch1;
  int index;

  while ((ch1 = getchar()) != EOF) {
    if (isalpha(ch1)) {
      index = tolower(ch1) - 'a';
      freq[index]++;
    }
  }

  char ch2;

  for (int i = 0; i < 26; i++) {
    if (freq[i] != 0) {
      ch2 = (char) (i + 'a');
      printf("%c %d\n", ch2, freq[i]);
    }
  }
  return 0;
}