#include <stdio.h>

int prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

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
        if (tab[i] < 2) {
            printf("%d  other\n", tab[i]);
        } else {
            printf("%d  %s\n", tab[i], prime(tab[i]) ? "prime" : "composite");
        }
    }
    return 0;
}
