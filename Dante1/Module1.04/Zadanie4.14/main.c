#include <stdio.h>

int is_non_monotonic(int a, int b, int c)
{
    return (a < b && b > c) || (a > b && b < c);
}

int main(void)
{
    int error;

    int array[4000];
    int size_of_array = 0;

    printf("Enter array: ");
    for(int i = 0; i < 4000; i++)
    {
        error = scanf("%i", &array[i]);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(array[i] == 0)
        {
            break;
        }
        size_of_array++;
    }
    if(size_of_array > 1000)
    {
        size_of_array = 1000;
    }

    if (size_of_array < 3)
    {
        printf("0\n0\n");
        return 0;
    }

    printf("\n");

    int max_length = 0;
    int counter_for_biggest_subarray = 0;
    int helper_for_array[1000];

    for (int i = 0; i < size_of_array - 2; i++)
    {
        int current_length = 2;
        while (i + current_length < size_of_array && is_non_monotonic(array[i + current_length - 2], array[i + current_length - 1], array[i + current_length]))
        {
            current_length++;
        }
        if (current_length > max_length)
        {
            max_length = current_length;
            counter_for_biggest_subarray = 1;
            helper_for_array[0] = i;
        }
        else if (current_length == max_length)
        {
            helper_for_array[counter_for_biggest_subarray++] = i;
        }
        i += current_length - 2;
    }

    if (max_length >= 3)
    {
        printf("%i\n%i\n", max_length, counter_for_biggest_subarray);
        for (int i = 0; i < counter_for_biggest_subarray; i++)
        {
            printf("%i -", helper_for_array[i]);
            for (int j = 0; j < max_length; j++)
            {
                printf(" %i", array[helper_for_array[i] + j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("0\n0\n");
    }

    return 0;
}
