#include <stdio.h>
#include "word_set.h"

int main()
{
    int error;

    union word_set d;

    printf("Enter: ");
    error = scanf("%i",&d.num);
    if(!error)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n%hu %hu",*(d.a + 0), *(d.a + 1));

    return 0;
}
