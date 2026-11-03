#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter 1-st number:");
    if (scanf("%d",&num1) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter second number:");
    if (scanf("%d",&num2) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%d\n", num1 + num2);
    printf("%d\n", num1 - num2);
    printf("%d\n", num1 * num2);

    if(num2 == 0)
    {
        printf("Operation not permitted");
    }
    else
    {
        printf("%d", num1 / num2);
    }
    return 0;
}
