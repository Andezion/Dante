#include <stdio.h>
#include <malloc.h>
#include "comparators.h"

typedef int operations(int, int);

int main()
{
    int error;

    int (**func)(int, int);
    func = malloc(4 * sizeof(int (*)(int, int)));
    if(func == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    *(func + 0) = comp_int;
    *(func + 1) = comp_int_abs;
    *(func + 2) = comp_int_length;
    *(func + 3) = comp_int_digits_sum;

    int size;
    printf("Enter size: ");
    error = scanf("%i", &size);
    if(error != 1)
    {
        printf("Incorrect input");

        free(func);

        return 1;

    }
    if(size < 1)
    {
        printf("Incorrect input data");

        free(func);

        return 2;
    }

    int *array = malloc(size * sizeof(int)); // create array
    if(array == NULL)
    {
        printf("Failed to allocate memory");

        free(func);

        return 8;
    }

    printf("Enter array: ");
    for(int i = 0; i < size; i++)
    {
        error = scanf("%i",(array + i));
        if(error != 1)
        {
            printf("Incorrect input");

            free(func);
            free(array);

            return 1;
        }
    }

    int pick;
    printf("Enter shit: ");
    error = scanf("%i", &pick);
    if(error != 1)
    {
        printf("Incorrect input");

        free(array);
        free(func);

        return 1;
    }
    if(pick < 0 || pick > 3)
    {
        printf("Incorrect input data");

        free(array);
        free(func);

        return 2;
    }

    sort_int(array, size, *(func + pick));
    for(int i = 0; i < size; ++i)
    {
        printf("%i ", *(array + i));
    }

    free(array);
    free(func);

    return 0;
}
