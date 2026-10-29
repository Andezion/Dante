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

void print_array(int array[4]) {
    for (int i = 0; i < 4; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");
}

void sum_rows(int matrix[4][4], int result[4]) {
    for (int i = 0; i < 4; i++) {
        result[i] = 0;
        for (int j = 0; j < 4; j++) {
            result[i] += matrix[i][j];
        }
    }
}

void sum_columns(int matrix[4][4], int result[4]) {
    for (int j = 0; j < 4; j++) {
        result[j] = 0;
        for (int i = 0; i < 4; i++) {
            result[j] += matrix[i][j];
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

    int result[4];
    sum_rows(matrix_a, result);
    print_array(result);

    sum_columns(matrix_a, result);
    print_array(result);

    sum_rows(matrix_b, result);
    print_array(result);

    sum_columns(matrix_b, result);
    print_array(result);

    sum_rows(matrix_c, result);
    print_array(result);

    sum_columns(matrix_c, result);
    print_array(result);

    return 0;
}
