#include <stdio.h>
#include "stack.h"

int main()
{
    int error;

    struct stack_t * stack;
    error = stack_init(&stack);
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

            stack_destroy(&stack);

            return 1;
        }

        if(pick == 1)
        {
            printf("Enter number: ");

            error = scanf("%i", &number);
            if (error != 1)
            {
                printf("Incorrect input\n");

                stack_destroy(&stack);
                
                return 1;
            }

            error = stack_push(stack, number);
            if (error != 0)
            {
                printf("Failed to allocate memory\n");

                stack_destroy(&stack);

                return 8;
            }
        }
        else if(pick == 2)
        {
            number = stack_pop(stack, &error);
            if (error == 1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("%d\n", number);
            }
        }
        else if(pick == 3)
        {
            error = stack_empty(stack);
            if (error == 2)
            {
                printf("Incorrect input\n");

                stack_destroy(&stack);

                return 1;
            }
            else
            {
                printf("%i\n", error);
            }
        }
        else if(pick == 4)
        {
            error = stack_empty(stack);
            if (error == 1)
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

    stack_destroy(&stack);
    return 0;
}
