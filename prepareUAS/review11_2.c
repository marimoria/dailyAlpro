# include <stdio.h>
# include <stdlib.h>

int** prefixsum(int** src, int baris, int kolom) {
    int **dest = (int**) malloc(baris * sizeof(int*));

    for (int i = 0; i < baris; i++) {
        dest[i] = (int*) malloc(kolom * sizeof(int));
    }

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (i == 0 && j == 0) {
                dest[i][j] = src[i][j];
            } else if (i == 0) {
                dest[i][j] = src[i][j] + dest[i][j-1];
            } else if (j == 0) {
                dest[i][j] = src[i][j] + dest[i-1][j];
            } else {
                dest[i][j] = src[i][j] + dest[i][j-1] + dest[i-1][j] - dest[i-1][j-1];
            }
        }
    }

    return dest;
}

int main() {
    int baris, kolom;
    scanf("%d %d", &baris, &kolom);
    
    int **matrix = (int**) malloc(baris * sizeof(int*));

    for (int i = 0; i < baris; i++) {
        matrix[i] = (int*) malloc(kolom * sizeof(int));
    }

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < baris; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int **result = prefixsum(matrix, baris, kolom);

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("%d", result[i][j]);

            if (j == kolom-1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }

    return 0;
}