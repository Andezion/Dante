#include <stdio.h>

int main()
{
    float num1, num2, num3, num4, num5;

    printf("Enter:\n");

    int check1 = scanf("%f", &num1);
    if (check1 != 1 || num1 == -1)
    {
        printf("Error");
        return 0;
    }

    int check2 = scanf("%f", &num2);
    if (check2 != 1 || num2 == -1)
    {
        printf("%.2f\n%.2f\n%.2f", num1, num1, num1);
        return 0;
    }

    int check3 = scanf("%f", &num3);
    if (check3 != 1 || num3 == -1)
    {
        float max;
        if (num1 > num2)
        {
            max = num1;
        }
        else
        {
            max = num2;
        }
        float min;
        if (num1 < num2)
        {
            min = num1;
        }
        else
        {
            min = num2;
        }
        float middle = (num1 + num2) / 2;

        printf("%.2f\n%.2f\n%.2f", min, max, middle);
        return 0;
    }

    int check4 = scanf("%f", &num4);
    if (check4 != 1 || num4 == -1)
    {
        float max = num1, min = num1, middle = (num1 + num2 + num3) / 3;

        if (num2 > max)
            max = num2;
        if (num2 < min)
            min = num2;

        if (num3 > max)
            max = num3;
        if (num3 < min)
            min = num3;

        printf("%.2f\n%.2f\n%.2f", min, max, middle);
        return 0;
    }

    int check5 = scanf("%f", &num5);
    if (check5 != 1 || num5 == -1)
    {
        float max = num1, min = num1, middle = (num1 + num2 + num3 + num4) / 4;

        if (num2 > max)
            max = num2;
        if (num2 < min)
            min = num2;

        if (num3 > max)
            max = num3;
        if (num3 < min)
            min = num3;

        if (num4 > max)
            max = num4;
        if (num4 < min)
            min = num4;

        printf("%.2f\n%.2f\n%.2f", min, max, middle);
        return 0;
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
