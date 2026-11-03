#include <stdio.h>

int main() {
    printf("Enter: ");
    int num1, num2;

    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("%d\n", num1 + num2);

    return 0;
}
