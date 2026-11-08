#include <stdio.h>

int main()
{
    float num1, num2;
    printf("Enter: ");

    if (scanf("%f",&num1) != 1) {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");
    if (scanf("%f",&num2) != 1) {
        printf("Incorrect input");
        return 1;
    }

    if((num1 + num2) * (num1 - num2) == num1 * num1 + num2 * num2) {
        printf("\ntozsamosc jest prawdziwa");
    } else {
        printf("\ntozsamosc nie jest prawdziwa");
    }

    return 0;
}
