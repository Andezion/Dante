#include <stdio.h>

int main() {
    printf("Enter 10 numbers:\n");

    int tab[10];
    for (int i = 0; i < 10; i = i + 2) {
        if (scanf("%d %d", &tab[i], &tab[i + 1]) != 2) {
            printf("Input data type error\n");
            return 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d  %s\n", tab[i], (tab[i] % 2 == 0) ? "even" : "odd");
    }
    return 0;
}
