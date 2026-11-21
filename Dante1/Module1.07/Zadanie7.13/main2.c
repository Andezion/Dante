#include <stdio.h>

int czy_pierwsza(int number) {
    if (number <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int goldbach(int number) {
    if (number < 4 || number % 2 != 0) {
        return 0;
    }

    int pointer = 0;
    for (int i = 2; i < number; i++) {
        int a = i, b = number - a;
        if (czy_pierwsza(a) && czy_pierwsza(b)) {
            printf("(%d, %d) ", a, b);
            pointer++;
        }
    }
    return pointer != 0;
}

int main() {
    int num1, num2;
    printf("Enter num1: ");

    if (scanf("%d", &num1) != 1) {
        printf("Incorrect input");
        return 1;
    }

    if (num1 % 2 != 0) num1++;

    printf("Enter num2: ");

    if (scanf("%d", &num2) != 1) {
        printf("Incorrect input");
        return 1;
    }

    if (num2 % 2 != 0) num2--;

    if (num1 > num2) {
        printf("Incorrect input");
        return 1;
    }


    for (int i = num1; i <= num2; i = i + 2) {
        printf("%d: ", i);
        if (!goldbach(i)) {
            
        }
        printf("\n");
    }

    return 0;
}
