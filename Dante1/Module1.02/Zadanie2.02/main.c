#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2, num3, num4;

    printf("Podaj numer telefonu: ");
    int scan = scanf("(%d) %d-%d-%d", &num1, &num2, &num3, &num4);
    if (scan < 4)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Numer kierunkowy: %.2d\n", num1);
    printf("Numer telfonu: %.3d-%.2d-%.2d", num2, num3, num4);
    return 0;
}
