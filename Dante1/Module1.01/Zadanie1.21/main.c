#include <stdio.h>

int main()
{
    float number;
    printf("Enter number: ");
    int check = scanf("%f",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n%.2f\n%.2f",number + 273.15,(number * 9 / 5) + 32);

    return 0;
}
