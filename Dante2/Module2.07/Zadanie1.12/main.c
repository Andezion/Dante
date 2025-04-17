#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int number;
    printf("Enter some shit: ");
    int error = scanf("%i", &number);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if (number < 1)
    {
        printf("Incorrect input data");
        return 2;
    }

    void (**help_me)(void) = easter(number, print_chicken, print_egg, print_rabbit);
    if (help_me == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for (int i = 0; i < number; i++)
    {
        (*(help_me + i))();
        printf("\n");
    }

    free(help_me);
    return 0;
}
