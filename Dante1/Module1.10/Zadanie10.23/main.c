#include <stdio.h>
#include "vector_utils.h"

int main()
{
    long long input[10];

    printf("Enter: ");

    int input_size = read_vector_ll(input, 10, -1);
    if(input_size == -1 || input_size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(input_size <= 1)
    {
        printf("Not enough data available");
        return 3;
    }

    long long output[10];
    int output_size = input_size;

    int check1 = product_left(input, input_size, output, output_size);
    if(check1 == 1)
    {
        printf("Incorrect input");
        return 1;
    }

    long long result[10];
    for(int i = 0 ; i < output_size; i++)
    {
        *(result + i) = *(output + i);
    }

    int check2 = product_right(input, input_size, output, output_size);
    if(check2 == 1)
    {
        printf("Incorrect input");
        return 1;
    }

    for(int i = 0 ; i < output_size; i++)
    {
        *(result + i) *= *(output + i);
    }

    printf("\n");
    display_vector_ll(result, output_size);

    return 0;
}
