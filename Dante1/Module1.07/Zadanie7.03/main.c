#include <stdio.h>
#include <math.h>

float circumference(float b);

int main()
{
    float number;

    printf("Enter radix: ");
    int check = scanf("%f",&number);
    if(check != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    float result = circumference(number);
    if(result == -1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Result is: %.4f",result);
    return 0;
}

float circumference(float b)
{
    if(b <= 0)
    {
        return -1;
    }
    return b * M_PI;
}
