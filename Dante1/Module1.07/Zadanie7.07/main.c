#include <stdio.h>

//add, subtract, multiply, divide

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float divide(float a, float b)
{
    if(b == 0)
    {
        return -1;
    }
    return a / b;
}

float multiply(float a, float b)
{
    return a * b;
}

int main()
{
    float num1, num2;

    printf("Enter num1: ");

    int check1 = scanf("%f",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter num2: ");

    int check2 = scanf("%f",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Suma: %.2f\n", add(num1, num2));
    printf("Roznica: %.2f\n", subtract(num1, num2));
    printf("Iloczyn: %.2f\n", multiply(num1, num2));
    float result = divide(num1, num2);
    if(result == -1 && (num2 != -1 && num1 != -1))
    {
        printf("Operation not permitted");
        return 0;
    }
    else
    {
        printf("Iloczyn: %.2f\n", result);
    }
    return 0;
}
