#include <stdio.h>
#include "vector_utils.h"
#include "quicksort.h"

int main()
{
    int vector[150];

    printf("Enter: ");

    int size = read_vector(vector, 150, 0);
    //printf("%i\n",size);
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
    if(size > 50)
    {
        size = 50;
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

    int check1 = quicksort(vector, size, type);
    if(check1 == 1)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    display_vector(vector,size);

    return 0;
}
