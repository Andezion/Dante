#include <stdio.h>

int main() {    
    int matrix[10][10] = { 0 };
    printf("Enter:\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1; 
            }
        }
    }

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            float value_to_put = (matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                matrix[i][j - 1] + matrix[i][j] + matrix[i][j + 1] +
                matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1]) / 9.0;
            printf("%.2f ", value_to_put);
        }
        printf("\n");
    }

    return 0;
}
