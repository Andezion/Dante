#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input_matrix(int matrix[15][15]) {
    printf("Enter:\n");

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }

            if (matrix[i][j] < 0 || matrix[i][j] >= 30) {
                printf("Value out of range\n");
                return 2;
            }
        }
    }

    return 0;
}

void print_matrix(int matrix[15][15]) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int counter(int number, int maxtrix[15][15]) {
    int count = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (maxtrix[i][j] == number) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL));

    int matrix[15][15];
    int result = input_matrix(matrix);
    if (result == 2) {
        return 2;
    } else if (result == 1) {
        return 1;
    }

    int result_matrix[15][15] = { 0 };
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            result_matrix[i][j] = counter(matrix[i][j], matrix);
        }
    }

    print_matrix(result_matrix);

    return 0;
}
