#include <stdio.h>

float add(float, float);

int main()
{
    float num1, num2;

    printf("Enter num1: ");

    int check1 = scanf("%f",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Enter num2: ");
    int check2 = scanf("%f",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("%f",add(num1, num2));

    return 0;
}

float add(float a, float b)
{
    return a + b;
}


