#include <stdio.h>

int main()
{
    double num1 = 6.0;
    int num2 = 2;

    printf("%i %i\n", (int)num1, num2);

    printf("%i\n", (int)num1 * num2);
    printf("%.2f\n", num1 / num2);
    printf("%i\n", (int)num1 + num2);
    printf("%i", (int)num1 - num2);
    
    return 0;
}
