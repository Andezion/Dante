#include <stdio.h>

int input_maxtrix(int **matrix, int rows, int cols) {
    printf("Enter: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int matrix[10][10] = { 0 };

    // if (input_maxtrix((int **)matrix, 10, 10) != 0) {
    //     return 1;
    // } 

    int to_find[2][2] = { 0 };
    // int to_find[2][2] = { 0 };
    // if (input_maxtrix((int **)matrix, 2, 2) != 0) {
    //     return 1;
    // }

    printf("Enter: ");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    printf("Enter: ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (scanf("%d", &to_find[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    int found = 0;
    int index = 0;
    int indexes[200] = { 0 };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrix[i][j] == to_find[0][0] && matrix[i][j + 1] == to_find[0][1] &&
                matrix[i + 1][j] == to_find[1][0] && matrix[i + 1][j + 1] == to_find[1][1]) {
                found++;
                indexes[index] = i;
                indexes[index + 1] = j;
                index += 2;
            }
        }
    }

    printf("%d\n", found);
    for (int i = 0; i < index; i += 2) {
        printf("%d %d\n", indexes[i + 1], indexes[i]);
    }

    return 0;
}
