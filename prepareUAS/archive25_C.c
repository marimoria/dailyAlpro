# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

int main() {
  int baris, kolom;
  scanf("%d %d", &baris, &kolom);
  
  int **matrix = (int**) malloc(baris * sizeof(int*));

  for (int i = 0; i < baris; i++) {
    matrix[i] = (int*) malloc(kolom * sizeof(int));
  }

  for (int i = 0; i < baris; i++) {
    for (int j = 0; j < kolom; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  int jumlahPetak = 0;
  while (jumlahPetak < (baris*kolom)) {
    int berat = 0;
    for (int i = 10; i > 0; i--) {
      for (int r = 0; r < baris; r++) {
        for (int c = 0; c < kolom; c++) {
          
        }
      }
    }
  }
  return 0;
}