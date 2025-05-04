#include <stdio.h>
#include "functions.h"

int main()
{
    int error;

    int pick;
    printf("Enter: ");

    error = scanf("%i", &pick);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    
    if (pick == 0)
    {
        unsigned int type;
        printf("Enter: ");

        error = scanf("%u",&type);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        int number_one = 0;
        int number_two = 0;

        COUNT_BITS(type, &number_one, &number_two)
        printf("%i\n%i\n", number_one, number_two);

        DISPLAY_BITS(type)
        printf("\n");

        REVERSE_BITS(&type)
        DISPLAY_BITS(type)
    }
    else if (pick == 2)
    {
        unsigned long type;
        printf("Enter: ");

        error = scanf("%lu",&type);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        int number_one = 0;
        int number_two = 0;

        COUNT_BITS(type, &number_one, &number_two)
        printf("%i\n%i\n", number_one, number_two);

        DISPLAY_BITS(type)
        printf("\n");

        REVERSE_BITS(&type)
        DISPLAY_BITS(type)
    }
    else if (pick == 1)
    {
        unsigned short type;
        printf("Enter: ");

        error = scanf("%hu",&type);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        int number_one = 0;
        int number_two = 0;

        COUNT_BITS(type, &number_one, &number_two)
        printf("%i\n%i\n", number_one, number_two);

        DISPLAY_BITS(type)
        printf("\n");

        REVERSE_BITS(&type)
        DISPLAY_BITS(type)
    }
    else
    {
        printf("Incorrect input data");
        return 2;
    }

    return 0;
}
