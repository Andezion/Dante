#include <stdio.h>
#include "types_utils.h"
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    int vector[150];

    printf("Enter: ");

    int size = read_vector(vector, 150, 0);
    if(size == -2)
    {
        printf("Incorrect input\n");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available\n");
        return 3;
    }

    int type;
    printf("\nEnter: ");
    int check = scanf("%i",&type);
    if(check != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    if(type != 1 && type != 2)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    printf("\n");

    int new_type;
    printf("\nEnter: ");
    int new_check = scanf("%i",&new_type);
    if(new_check != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    if(new_type != 1 && new_type != 2 && new_type != 3)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    printf("\n");

    int check1 = sort(vector, size, type, new_type);
    if(check1 == 1)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    return 0;
}
