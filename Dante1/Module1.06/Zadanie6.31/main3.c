#include <stdio.h>
#include <limits.h>

#define SIZE 10

int main(void) {
    int matrix[SIZE][SIZE];
    int best = INT_MIN;
    int count = 0;

    printf("Enter:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 2; j++) {
            int row_sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            int col_sum = matrix[j][i] + matrix[j + 1][i] + matrix[j + 2][i];

            if (row_sum > best) {
                best = row_sum;
                count = 1;
            } else if (row_sum == best) {
                count++;
            }

            if (col_sum > best) {
                best = col_sum;
                count = 1;
            } else if (col_sum == best) {
                count++;
            }
        }
    }

    printf("Max sum = %d\n", best);
    printf("Count = %d\n", count);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 2; j++) {
            int row_sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            int col_sum = matrix[j][i] + matrix[j + 1][i] + matrix[j + 2][i];

            if (row_sum == best) {
                printf("2 %d %d\n", i, j);
            }

            if (col_sum == best) {
                printf("1 %d %d\n", j, i);
            }
        }
    }

    return 0;
}
