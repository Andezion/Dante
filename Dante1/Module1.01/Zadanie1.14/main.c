#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Enter 1-st number:");
    int check1 = scanf("%f",&num1);
    if(check1 != 1)
    {
        return 1;
    }

    printf("Enter second number:");
    int check2 = scanf("%f",&num2);
    if(check2 != 1)
    {
        return 1;
    }

    printf("%f\n", num1 + num2);
    printf("%f\n", num1 - num2);
    printf("%f\n", num1 * num2);
    printf("%f", num1 / num2);
    return 0;
}
