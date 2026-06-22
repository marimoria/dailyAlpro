#include <stdio.h>
#include <stdlib.h>

int* get_array_from_input(int *final_count, int sentinel) {
  int capacity = 2;
  int count = 0;
  int *arr = (int*) malloc(capacity * sizeof(int));
  int val;

  while (scanf("%d", &val) && val != sentinel) {
    if (count >= capacity) {
      capacity *= 2;
      arr = (int*) realloc(arr, capacity * sizeof(int));
    }
      arr[count++] = val;
    }
    
    *final_count = count;
    return realloc(arr, count * sizeof(int)); 
}

int main() {
  int n, m;
  int *array1 = get_array_from_input(&n, -9);
  int *array2 = get_array_from_input(&m, -9);

  int i = 0, j = 0;

  while (i < n || j < m) {
    if (i < n && j < m) {
      if (array1[i] <= array2[j]) {
        printf("%d ", array1[i++]);
      } else {
        printf("%d ", array2[j++]);
      }
    } else if (i < n) { // kalau ada yang udah abis tapi array1 belum abis
      printf("%d ", array1[i++]);
    } else { // kalau ada yang udah abis tapi array2 belum abis
      printf("%d ", array2[j++]);
    }
  }

  free(array1);
  free(array2);

  return 0;
}
