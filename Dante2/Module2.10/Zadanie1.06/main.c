#include <stdio.h>
#include "stack.h"

int main()
{
    int error;
    unsigned long long number;

    struct stack_t *stack;
    error = stack_init(&stack);
    if(error != 0)
    {
        return printf("Failed to allocate memory"), 8;
    }

    printf("Enter: ");
    error = scanf("%llu", &number);
    if(error != 1)
    {
        return stack_destroy(&stack), printf("Incorrect input"), 1;
    }

    if(number == 0)
    {
        return printf("0"), stack_destroy(&stack), 0;
    }

    for(; number > 0;)
    {
        error = stack_push(stack, (int)(number % 2));
        if(error != 0)
        {
            return printf("Failed to allocate memory"), stack_destroy(&stack), 8;
        }
        number = number / 2;
    }

    stack_display(stack);
    stack_destroy(&stack);

    return 0;
}
