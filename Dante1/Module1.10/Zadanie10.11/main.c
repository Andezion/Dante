#include <stdio.h>
#include "vector_utils.h"

int main()
{
    int array[150];

    printf("Enter smth: ");

    int size = read_vector(array, 150, 0);
    if(size == -1 || size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }
    if(size > 150)
    {
        size = 150;
    }

    while(getchar()!='\n');

    int positions_to_shift;
    printf("Enter again: ");

    int check1 = scanf("%i",&positions_to_shift);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    

    int dir;
    printf("Enter: ");
    int check2 = scanf("%i",&dir);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(dir != 1 && dir != 2)
    {
        printf("Incorrect input data");
        return 2;
    }

    int check3 = shift(array,size,positions_to_shift,dir);
    if(check3 != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    display_vector(array, size);

    return 0;
}
