#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter 1-st number:");
    if (scanf("%d",&num1) != 1)
    {
        return 1;
    }

    printf("Enter second number:");
    if( scanf("%d",&num2) != 1)
    {
        return 1;
    }
    
    printf("%i\n%i\n%i\n%i", num1 + num2, num1 - num2, num1 * num2, num1 / num2);
    return 0;
}
