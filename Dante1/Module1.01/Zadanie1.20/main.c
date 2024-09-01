#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1, num2, num3;

    float kut1;
    float kut2;

    printf("Enter num1: ");
    int check1 = scanf("%f", &num1);
    if(check1 != 1)
    {
        return 1;
    }

    printf("Enter num2: ");
    int check2 = scanf("%f", &num2);
    if(check2 != 1)
    {
        return 1;
    }

    num3 = sqrt(num1 * num1 + num2 * num2);
    printf("Result is: %.2f\n", num3);

    kut1 = asin((num1 / num3)) * 180 / 3.14159265359;
    kut2 = asin((num2 / num3)) * 180 / 3.14159265359;

    printf("%.2f\n", kut1);
    printf("%.2f", kut2);
    return 0;
}
