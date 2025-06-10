#include <stdio.h>
#include "vector_utils.h"


int main()
{
    int vector[100];
    int size;

    printf("Enter smth:\n");

    int check1 = read_vector(vector, 100, -1);
    if(check1 == -1)
    {
        printf("Not enough data available");
        return 3;
    }
    if(check1 == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(check1 < 1)
    {
        printf("Not enough data available");
        return 3;
    }

    size = check1;

    int check2 = sort(vector, size);
    if(check2 == 1)
    {
        printf("Incorrect input");
        return 1;
    }

    display_vector(vector, size);

    return 0;
}

