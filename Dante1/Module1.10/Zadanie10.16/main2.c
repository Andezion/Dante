#include <stdio.h>

int is_prime(int a) {
    if (a < 2) {
        return 0;
    }
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    printf("Enter a table:\n");

    int table[10][10] = { 0 };
    int number_counter = 0;
    
    while (number_counter != 100) {
        int number;
        if (scanf("%d", &number) != 1) {
            printf("Incorrect input\n");
            return 1;
        }

        if (is_prime(number) == 1) {
            *(*(table + number_counter / 10) + number_counter % 10) = number;
            number_counter++;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i % 3 == 0 && j % 3 == 0) {
                printf("%d ", *(*(table + i) + j));
            }
        }
    }

    return 0;
}
