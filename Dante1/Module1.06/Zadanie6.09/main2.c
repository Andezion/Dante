#include <stdio.h>

int input_matrix(int matrix[10][10]) {
    printf("Enter:\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int matrix[10][10];
    int result = input_matrix(matrix);
    if (result == 1) {
        return 1;
    }

    result = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 == 0 ) {
                result += matrix[i][j];
            } else {
                result -= matrix[i][j];
            }
        }
    }

    printf("%d\n", result);

    return 0;
}
