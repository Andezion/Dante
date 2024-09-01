#include <stdio.h>

int main()
{
    float number;

    printf("Enter: ");
    int check = scanf("%f",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(number > 0)
    {
        printf("\ndodatnia");
    }
    else if(number == 0)
    {
        printf("\nzerowa");
    }
    else
    {
        printf("\nujemna");
    }

    return 0;
}
