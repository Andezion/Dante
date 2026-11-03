#include <stdio.h>

int main(void) {
    printf("Enter: ");

    int a;
    char b;
    if (scanf("%c%d", &b, &a) != 2 || a < 1 || a > 8 || (b < 'a' || b > 'h')) {
        printf("Incorrect input\n");
        return 1;
    }

    if ((b % 2 != 0) == (a % 2 == 0)) {
        printf("white\n");
    } else {
        printf("black\n");
    }
    return 0;
}
