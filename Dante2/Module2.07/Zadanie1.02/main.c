#include <stdio.h>
#include "int_operations.h"

int main()
{
    int error;

    int a, b;
    printf("Enter: ");
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
    if(type < 0 || type > 3)
    {
        printf("Incorrect input data");
        return 2;
    }

    add_int(a, b);
    sub_int(a, b);
    mul_int(a, b);
    div_int(a, b);

    printf("%i", get_function(type)(a, b));

    return 0;
}
