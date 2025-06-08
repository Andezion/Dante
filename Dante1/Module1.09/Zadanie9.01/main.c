#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int main()
{
    int tab[150] = { 0 };

    printf("Enter data:\n");

    int size = read_vector(tab,150,0);
    if(size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }
    if(size == 1)
    {
        printf("%i",tab[0]);
        return 0;
    }

    int check = bubble_sort(tab, size);
    if(check == 1)
    {
        printf("Incorrect input");
        return 1;
    }
    return 0;
}
