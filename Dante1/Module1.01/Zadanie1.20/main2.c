#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2, num3;

    printf("Enter num1: ");
    if (scanf("%f", &num1) != 1)
    {
        return 1;
    }

    printf("Enter num2: ");
    if (scanf("%f", &num2) != 1)
    {
        return 1;
    }

    num3 = sqrt(num1 * num1 + num2 * num2);
    printf("Result is: %.2f\n", num3);

    printf("%.2f\n", asin((num1 / num3)) * 180 / 3.14159265359);
    printf("%.2f", asin((num2 / num3)) * 180 / 3.14159265359);
    return 0;
}
