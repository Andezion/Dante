#include <stdio.h>
#include "bit_set.h"

int main()
{
    int error;

    union bit_set d;

    printf("Enter: ");
    error = scanf("%hhd",&d.letter);
    if(!error)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n%i %i %i %i %i %i %i %i",d.array.x8,d.array.x7,d.array.x6,d.array.x5,d.array.x4,d.array.x3,d.array.x2,d.array.x1);

    return 0;
}
