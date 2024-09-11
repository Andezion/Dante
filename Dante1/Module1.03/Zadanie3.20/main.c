#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter: ");

    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");

    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("\nIncorrect input");
        return 1;
    }

    if(num2 < num1)
    {
        printf("\nIncorrect range");
        return 2;
    }

    while (num1 != num2 + 1)
    {
        printf("%i ",num1);
        num1++;
    }

    return 0;
}
