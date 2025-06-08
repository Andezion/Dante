#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"

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



    int check1 = bubble_sort(vector, size, type);
    if(check1 == 1)
    {
        printf("Incorrect input data\n");
        return 2;
    }


    return 0;
}
