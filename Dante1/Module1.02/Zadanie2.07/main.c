
#include <stdio.h>

int main()
{
    double num1, num2, num3;

    printf("Enter number: ");

    int check = scanf("%lf", &num1);
    if (check != 1 || num1 < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    if (num1 <= 50)
    {
        num2 = num1 * 0.50;
    }
    else if (num1 <= 150)
    {
        num2 = 50 * 0.50 + (num1 - 50) * 0.75;
    }
    else if (num1 <= 250)
    {
        num2 = 50 * 0.50 + 100 * 0.75 + (num1 - 150) * 1.20;
    }
    else
    {
        num2 = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (num1 - 250) * 1.50;
    }

    num3 = num2 * (1 + 0.22);

    printf("Result is: %lf\n", num3);

    return 0;
}
