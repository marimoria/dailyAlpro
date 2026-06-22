#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  scanf("%d", &N);

  int* array = (int*) malloc(N * sizeof(int));
  int* dp = (int*) malloc(N * sizeof(int)); 
  
  int max_lis = 0;

  for (int i = 0; i < N; i++) {
    scanf("%d", &array[i]);
    dp[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (array[j] < array[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
    if (dp[i] > max_lis) max_lis = dp[i];
  }

  printf("%d\n", N - max_lis);

  free(array);
  free(dp);
  return 0;
}
