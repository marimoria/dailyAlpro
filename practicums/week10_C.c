#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, nilai;
  scanf("%d", &N);

  int* PS = (int*) malloc((N+1) * sizeof(int));

  PS[0] = 0;

  for (int i = 1; i <= N; i++) {
    scanf("%d", &nilai);
    PS[i] = nilai + PS[i-1];
  }

  int left, right;

  while(scanf("%d", &left) == 1 && (left != -9)) {
    if (scanf("%d", &right) == 1) {
      printf("%d\n", PS[right] - PS[left-1]);
    }
  }

  free(PS);
  return 0;
}
