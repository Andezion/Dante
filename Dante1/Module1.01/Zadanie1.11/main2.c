#include <stdio.h>

int main() {
    int number;
    printf("Enter number: ");

    if (scanf("%i",&number) != 1) {
        printf("Incorrect input");
        return 1;
    }

    printf("%i\n%i",number, number * 10);
    return 0;
}
