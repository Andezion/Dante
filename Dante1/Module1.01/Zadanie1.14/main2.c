#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Enter 1-st number:");
    if (scanf("%f",&num1) != 1)
    {
        return 1;
    }

    printf("Enter second number:");
    if( scanf("%f",&num2) != 1)
    {
        return 1;
    }
    
    printf("%f\n%f\n%f\n%f", num1 + num2, num1 - num2, num1 * num2, num1 / num2);
    return 0;
}
