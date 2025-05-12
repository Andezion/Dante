#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main()
{
    int error;

    struct doubly_linked_list_t *stack = dll_create();
    if (stack == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int number;

    printf("Enter numbers: ");
    for (;;)
    {
        error = scanf("%i", &number);
        if (error != 1)
        {
            return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
        }

        if (number == -1)
        {
            break;
        }

        if (dll_push_back(stack, number))
        {
            return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
        }
    }

    if (stack->head == NULL)
    {
        return printf("Not enough data available"), free(stack), 3;
    }


    printf("Popipo pipo popi po: ");
    error = scanf("%i", &number);
    if (error != 1)
    {
        return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
    }

    if (number == 1)
    {
        dll_sort_desc(stack);
    }
    else if (number == 0)
    {
        dll_sort_asc(stack);
    }
    else
    {
        return printf("Incorrect input data"), dll_clear(stack), free(stack), 2;
    }


    return dll_display(stack), printf("\n"), dll_display_reverse(stack), dll_clear(stack), free(stack), 0;
}

