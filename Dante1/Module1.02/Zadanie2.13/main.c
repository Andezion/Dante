#include <stdio.h>

int main()
{
    float num1, num2, num3, num4, num5;

    printf("Enter:\n");

    int check = scanf("%f %f %f %f %f",&num1, &num2, &num3, &num4, &num5);
    if(check != 5)
    {
        printf("Incorrect input");
        return 1;
    }

    float sum = num1 + num2 + num3 + num4 + num5;
    float middle = sum / 5;

    float max = num1;
    if (num2 > max)
    {
        max = num2;
    }
    if (num3 > max)
    {
        max = num3;
    }
    if (num4 > max)
    {
        max = num4;
    }
    if (num5 > max)
    {
        max = num5;
    }

    float min = num1;
    if (num2 < min)
    {
        min = num2;
    }
    if (num3 < min)
    {
        min = num3;
    }
    if (num4 < min)
    {
        min = num4;
    }
    if (num5 < min)
    {
        min = num5;
    }

    printf("\n%.2f\n%.2f\n%.2f",min,max,middle);
    return 0;
}
