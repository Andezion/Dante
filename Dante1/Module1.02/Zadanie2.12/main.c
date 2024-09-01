#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2, num3;

    printf("Enter: ");
    int check1 = scanf("%f",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");
    int check2 = scanf("%f",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");
    int check3 = scanf("%f",&num3);
    if(check3 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(num1 == 0 && num2 == 0 && num3 == 0)
    {
        printf("nieskonczonosc");
        return 0;
    }

    if(num1 == 0 && num2 == 0)
    {
        printf("brak");
        return 0;
    }

    if(num1 == 0)
    {
        printf("\nJeden: %f",-num3 / num2);
        return 0;
    }

    float disc = num2 * num2 - 4 * num1 * num3;
    if(disc == 0)
    {
        printf("\nJeden: %f",(-1 * num2) / (2 * num1));
        return 0;
    }
    else if(disc < 0)
    {
        printf("Brak");
        return 0;
    }

    printf("\nDwa: %f %f",(-num2 + sqrtf(disc)) / (2 * num1), (-num2 - sqrtf(disc)) / (2 * num1));

    return 0;
}
