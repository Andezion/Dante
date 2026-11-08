#include <stdio.h>

int main()
{
    float number;

    printf("Enter: ");
    if (scanf("%f",&number) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(number > 0) {
        printf("\ndodatnia");
    } else if(number == 0) {
        printf("\nzerowa");
    } else {
        printf("\nujemna");
    }

    return 0;
}
