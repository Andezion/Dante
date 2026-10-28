#include <stdio.h>

int main(void) {
    int matrix[5][5];
    printf("Enter:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j || i + j == 4) {
                printf("%3d ", matrix[i][4 - j]);
            } else {
                printf("%3d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
