#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter 1-st number:");
    int check1 = scanf("%d",&num1);
    if(check1 != 1)
    {
        return 1;
    }

    printf("Enter second number:");
    int check2 = scanf("%d",&num2);
    if(check2 != 1)
    {
        return 1;
    }
    
    printf("%i\n", num1 + num2);
    printf("%i\n", num1 - num2);
    printf("%i\n", num1 * num2);
    printf("%i", num1 / num2);
    return 0;
}
