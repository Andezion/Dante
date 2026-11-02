#include <stdio.h>

int main()
{
    float number;
    printf("Enter number: ");
    if (scanf("%f",&number) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n%.2f\n%.2f",number + 273.15,(number * 9 / 5) + 32);

    return 0;
}
