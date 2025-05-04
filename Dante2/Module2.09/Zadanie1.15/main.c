#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

DEFINE_ARRAY(int)
CREATE_ARRAY(int)
FREE_ARRAY(int)
SAVE_ARRAY(int)
LOAD_ARRAY(int)
SORT_ARRAY(int)
DEFINE_ARRAY(double)
CREATE_ARRAY(double)
FREE_ARRAY(double)
SAVE_ARRAY(double)
LOAD_ARRAY(double)
SORT_ARRAY(double)

int main(void)
{
    int error;

    char *filename = malloc(sizeof(char) * 30);
    if(!filename)
    {
        return printf("Failed to allocate memory"), 8;
    }

    printf("Enter filename: ");
    scanf("%29[^\n]", filename);

    int pick;
    printf("Enter: ");
    error = scanf("%d", &pick);
    if(error != 1)
    {
        return printf("Incorrect input"), free(filename), 1;
    }

    if(pick < 0 || pick > 1)
    {
        return printf("Incorrect input data"), free(filename), 2;
    }


    int val1;
    int val2;
    int val3;

    if (pick != 0)
    {
        struct array_double_t *stack;
        val1 = load_array_double(&stack, filename);
        switch (val1)
        {
            case 1:
                return printf("Incorrect input data"), free(filename), 2;
            case 2:
                return printf("Couldn't open file"), free(filename), 4;
            case 3:
                return printf("File corrupted"), free(filename), 6;
            case 4:
                return printf("Failed to allocate memory"), free(filename), 8;
            default:
                break;
        }

        val2 = sort_array_double(stack);
        if (val2 != 0)
        {
            return printf("Incorrect input data"), free_array_double(stack), free(filename), 2;
        }

        val3 = save_array_double(stack, filename);
        if (val3 == 2)
        {
            return printf("Couldn't create file"), free_array_double(stack), free(filename), 5;
        }

        free_array_double(stack);
        free(filename);
    }
    else
    {
        struct array_int_t *stack;
        val1 = load_array_int(&stack, filename);

        switch (val1)
        {
            case 1:
                return printf("Incorrect input data"), free(filename), 2;
            case 2:
                return printf("Couldn't open file"), free(filename), 4;
            case 3:
                return printf("File corrupted"), free(filename), 6;
            case 4:
                return printf("Failed to allocate memory"), free(filename), 8;
            default:
                break;
        }


        val2 = sort_array_int(stack);
        if (val2 != 0)
        {
            return printf("Incorrect input data"), free_array_int(stack), free(filename), 2;
        }

        val3 = save_array_int(stack, filename);
        if (val3 == 2)
        {
            return printf("Couldn't create file"), free_array_int(stack), free(filename), 5;

        }

        free_array_int(stack);
        free(filename);
    }

    return printf("File saved"), 0;
}

