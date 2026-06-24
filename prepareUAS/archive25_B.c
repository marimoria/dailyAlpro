# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int n, int* arr) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

int main() {
  int baris, kolom;
  scanf("%d %d", &baris, &kolom);
  
  int **matrix = (int**) malloc(baris * sizeof(int*));
  int *toSort = (int*) malloc((baris*kolom) * sizeof(int));

  for (int i = 0; i < baris; i++) {
    matrix[i] = (int*) malloc(kolom * sizeof(int));
  }

  for (int i = 0; i < baris; i++) {
    for (int j = 0; j < kolom; j++) {
      scanf("%d", &matrix[i][j]);
      toSort[(i*kolom) + j] = matrix[i][j];
    }
  }

  bubbleSort((baris*kolom), toSort);

  for (int i = 0; i < baris; i++) {
    for (int j = 0; j < kolom; j++) {
      matrix[i][j] = toSort[(i*kolom) + j];
    }
  }

  for (int i = 0; i < baris; i++) {
    for (int j = 0; j < kolom; j++) {
      printf("%d", matrix[i][j]);

      if (j == kolom-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }

  return 0;
}