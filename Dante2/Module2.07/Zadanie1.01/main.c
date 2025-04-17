#include <stdio.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int error;

    int a, b;
    printf("Enter a und b: ");
    error = scanf("%i %i",&a, &b);
    if(error != 2)
    {
        printf("Incorrect input");
        return 1;
    }

    int type;
    printf("Enter type: ");
    error = scanf("%i",&type);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    switch (type)
    {
        case 0:
            printf("%i", calculate(a, b, add_int));
            break;
        case 1:
            printf("%i", calculate(a, b, sub_int));
            break;
        case 2:
            if(b == 0)
            {
                printf("Incorrect input data");
                return 2;
            }
            printf("%i", calculate(a, b, div_int));
            break;
        case 3:
            printf("%i", calculate(a, b, mul_int));
            break;
        default:
            printf("Incorrect input data");
            return 2;
    }

    return 0;
}
