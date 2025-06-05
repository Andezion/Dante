#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b);

int main()
{
    int num1, num2;

    printf("Enter a: ");
    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter b: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int result = GCD(num1, num2);

    printf("\nResult is: %i",result);

    return 0;
}

int GCD(int a, int b)
{
    int new_a = abs(a);
    int new_b = abs(b);
    if(new_b == 0)
    {
        return new_a;
    }
    return GCD(new_b,new_a % new_b);
}
