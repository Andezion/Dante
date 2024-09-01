#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter num1: ");

    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter num2: ");

    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(num2 == 0)
    {
        printf("Operation not permitted");
        return 1;
    }
    else if(num1 % num2 == 0)
    {
        printf("%i is divisible by %i",num1,num2);
    }
    else
    {
        printf("%i is not divisible by %i",num1,num2);
    }
    return 0;
}
