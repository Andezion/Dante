#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, num3;

    printf("Podaj wartosci num1:");
    if (scanf("%i",&num1) != 1)
    {
        return 1;
    }

    printf("Podaj wartosci num2:");
    if (scanf("%i",&num2) != 1)
    {
        return 1;
    }

    printf("Podaj wartosci num3:");
    if (scanf("%i",&num3) != 1)
    {
        return 1;
    }

    printf("%.2f", sqrt((num1 * num1) + (num2 * num2) + (num3 * num3)));

    return 0;
}
