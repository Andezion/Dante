#include <stdio.h>
#include "vector_utils.h"

int main()
{
    float vec[100];
    printf("Enter: ");
    int size = read_vector_float(vec, 100, -1);
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

    int out[11] = { 0 };
    int check = create_histogram(vec, size, out, 11);
    if(check != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");
    display_vector(out, 11);

    return 0;
}
