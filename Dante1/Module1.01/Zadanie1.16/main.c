#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, num3;

    printf("Podaj wartosci num1:");
    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        return 1;
    }

    printf("Podaj wartosci num2:");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        return 1;
    }

    printf("Podaj wartosci num3:");
    int check3 = scanf("%i",&num3);
    if(check3 != 1)
    {
        return 1;
    }

    float result = sqrt((num1 * num1) + (num2 * num2) + (num3 * num3));

    printf("%.2f", result);

    return 0;
}
