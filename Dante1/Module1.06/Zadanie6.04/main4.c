#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input_matrix(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int matrix_a[4][4], matrix_b[4][4], matrix_c[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    input_matrix(matrix_a);
    input_matrix(matrix_b);

    print_matrix(matrix_a);
    print_matrix(matrix_b);
    print_matrix(matrix_c);

    return 0;
}
