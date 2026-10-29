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

void print_matrix(int matrix[4][4], int type) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix[i][j] * type);
        }
        printf("\n");
    }
    printf("\n");
}

void multiply_matrices(int matrix_a[4][4], int matrix_b[4][4], int result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int matrix_a[4][4], matrix_b[4][4], matrix_c[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    input_matrix(matrix_a);
    input_matrix(matrix_b);

    print_matrix(matrix_a, 1);
    print_matrix(matrix_b, 1);
    print_matrix(matrix_c, 1);

    int result[4][4];
    multiply_matrices(matrix_a, matrix_b, result);
    print_matrix(result, 1);

    multiply_matrices(matrix_b, matrix_a, result);
    print_matrix(result, 1);

    multiply_matrices(matrix_a, matrix_c, result);
    print_matrix(result, 1);

    multiply_matrices(matrix_c, matrix_a, result);
    print_matrix(result, 1);

    return 0;
}
