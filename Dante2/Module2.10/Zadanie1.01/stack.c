#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void stack_display(const struct stack_t *stack)
{
    if (stack == NULL || stack->data == NULL || stack->head > stack->capacity || stack->capacity <= 0 || stack->head <= 0)
    {
        return;
    }

    for(int i = stack->head - 1; i >= 0; i--)
    {
        printf("%i ", *(stack->data + i));
    }
}

void stack_free(struct stack_t *stack)
{
    if (stack == NULL)
    {
        return;
    }

    if (stack->data == NULL)
    {

    }
    else
    {
        free(stack->data);
    }

    free(stack);
}

int stack_init(struct stack_t **stack, int N)
{
    if (stack == NULL || N <= 0)
    {
        return 1;
    }

    *stack = malloc(sizeof(struct stack_t));
    if (*stack == NULL)
    {
        return 2;
    }

    (*stack)->data = malloc(N * sizeof(int));
    if ((*stack)->data == NULL)
    {
        free(*stack);
        *stack = NULL;

        return 2;
    }

    (*stack)->capacity = N;
    (*stack)->head = 0;

    return 0;
}

int stack_pop(struct stack_t *stack, int *err_code)
{
    if (stack == NULL || stack->data == NULL || stack->capacity <= 0 || stack->head < 0 || stack->head > stack->capacity)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return 1;
    }

    if(stack->head == 0)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return 2;
    }

    stack->head = stack->head - 1;
    int returning_value = *(stack->data + stack->head);

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return returning_value;
}

int stack_push(struct stack_t *stack, int value)
{
    if (stack == NULL || stack->data == NULL || stack->head > stack->capacity || stack->capacity <= 0 || stack->head < 0)
    {
        return 1;
    }

    if(stack->capacity == stack->head)
    {
        int *little_helper = realloc(stack->data, sizeof(int) * 2 * stack->capacity);
        if (little_helper != NULL)
        {
            stack->capacity = stack->capacity * 2;
            stack->data = little_helper;
        }
        else
        {
            return 2;
        }
    }

    *(stack->data+stack->head) = value;
    stack->head = stack->head + 1;

    return 0;
}
