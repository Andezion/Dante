#include <stdio.h>
#include "stack.h"

int main()
{
    int error;

    struct stack_t *stack;
    error = stack_init(&stack, 10);
    if(error == 1)
    {
        printf("Incorrect input data");
        return 2;
    }
    if (error == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int number;
    int pick = -1;
    while(pick != 0)
    {
        printf("Enter what to do: ");

        error = scanf("%i", &pick);
        if (error != 1)
        {
            printf("Incorrect input");

            stack_free(stack);

            return 1;
        }

        if(pick == 1)
        {
            printf("Enter number: ");

            error = scanf("%i", &number);
            if (error != 1)
            {
                printf("Incorrect input");

                stack_free(stack);

                return 1;
            }
            error = stack_push(stack, number);
            if (error == 1)
            {
                printf("Incorrect input data");

                stack_free(stack);

                return 2;
            }
            if (error == 2)
            {
                printf("Failed to allocate memory");

                stack_free(stack);

                return 8;
            }
        }
        else if(pick == 2)
        {
            number = stack_pop(stack, &error);
            if (error == 2)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("%i\n", number);
            }
        }
        else if(pick == 3)
        {
            if (stack->head == 0)
            {
                printf("Stack is empty\n");
            }
            else
            {
                stack_display(stack);
                printf("\n");
            }
        }
        else
        {
            if(pick != 0)
            {
                printf("Incorrect input data\n");
            }
        }
    }

    stack_free(stack);

    return 0;
}
