#include <stdio.h>

int main()
{
    float num1, num2;
    printf("Enter: ");

    int check1 = scanf("%f",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");
    int check2 = scanf("%f",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if((num1 + num2) * (num1 - num2) == num1 * num1 + num2 * num2)
    {
        printf("\ntozsamosc jest prawdziwa");
    }
    else
    {
        printf("\ntozsamosc nie jest prawdziwa");
    }

    return 0;
}
