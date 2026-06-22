# include <stdio.h>
# include <ctype.h>

int main() {
  int n;
  char ch1, ch2, ch3;

  scanf("%d", &n);
  scanf(" %c%c%c", &ch1, &ch2, &ch3);

  printf("%c\n", ch1);

  for (int i = 1; i < n - 1; i++) {
    printf("%c", ch1);

    for(int j = 0; j < i - 1; j++) {
      printf(" ");
    }

    printf("%c\n", ch3);
  }

  for (int i = 0; i < n-1; i++) {
    printf("%c", ch2);
  }

  printf("%c\n", ch3);

  return 0;
}