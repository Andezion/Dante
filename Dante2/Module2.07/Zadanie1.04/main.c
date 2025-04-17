#include <stdio.h>
#include "for_loop.h"

int main()
{
    int error;
    void (*types[4])(double) = {print_value, print_accumulated, print_square, print_abs};

    double num1;
    double num2;
    double num3;

    printf("Enter your numbers: ");
    error = scanf("%lf %lf %lf",&num1,&num2,&num3);
    if(error != 3)
    {
        printf("Incorrect input");
        return 1;
    }

    if(num2 > 0 && num1 > num3)
    {
        printf("Incorrect input data");
        return 2;
    }
    if(num1 < num3 && num2 < 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    if(num2 == 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int type;

    printf("Enter your type: ");
    error = scanf("%i",&type);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(type < 0 || type > 3)
    {
        printf("Incorrect input data");
        return 2;
    }

    for_loop(num1, num2, num3, *(types + type));
    return 0;
}
