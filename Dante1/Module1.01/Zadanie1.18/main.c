#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, num3, num4, num5;
    printf("Enter 5 numbers:");

    int check = scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
    if(check != 5)
    {
        return 1;
    }

    printf("Wynik: %.4f",((num1 + num2 + num3 + num4 + num5) / 5));
    return 0;
}
