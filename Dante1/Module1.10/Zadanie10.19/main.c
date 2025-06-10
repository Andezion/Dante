#include <stdio.h>
#include "vector_utils.h"

int main()
{
    int tab[100];

    printf("Enter: ");
    int size = read_vector(tab, 100, 0);
    if(size == -2 || size == -1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }

    printf("\n");
    display_vector(tab, size);

    int check = reverse_vector(tab, size);
    if(check == -1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");
    display_vector(tab, size);

    return 0;
}
