#include <stdio.h>

float quadratic_equation(float a, float b, float c, float x)
{
    return a * x * x + b * x + c;
}

int main()
{
    float a, b, c, x;

    printf("Enter: ");

    int check1 = scanf("%fx^2%fx%f", &a, &b, &c);
    if (check1 != 3)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\nEnter x: ");

    int check2 = scanf("%f", &x);
    if (check2 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    float result = quadratic_equation(a, b, c, x);
    printf("\nResult: %f\n", result);

    return 0;
}
