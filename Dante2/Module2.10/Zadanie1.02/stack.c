#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int stack_empty(const struct stack_t* stack)
{
    if (stack == NULL)
    {
        return 2;
    }

    if (stack->head == NULL)
    {
        return 1;
    }
    return 0;
}

void stack_destroy(struct stack_t** stack)
{
    if (stack == NULL || *stack == NULL)
    {
        return;
    }

    struct node_t *working_on_that;
    working_on_that = (*stack)->head;

    for (; working_on_that;)
    {
        struct node_t *helper;
        helper = working_on_that;

        working_on_that = working_on_that->next;
        free(helper);
    }

    free(*stack);
    *stack = NULL;
}

int stack_pop(struct stack_t* stack, int *err_code)
{
    if (stack == NULL || stack->head == NULL)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return -1;
    }

    struct node_t *working_on_that;
    working_on_that = stack->head;

    int result = working_on_that->data;
    stack->head = working_on_that->next;

    free(working_on_that);
    if (err_code)
    {
        *err_code = 0;
    }
    return result;
}

void stack_display(const struct stack_t* stack)
{
    if (stack == NULL)
    {
        return;
    }

    struct node_t *working_on_that;
    working_on_that = stack->head;

    for (; working_on_that != NULL;)
    {
        printf("%i ", working_on_that->data);

        working_on_that = working_on_that->next;
    }
}

int stack_push(struct stack_t *stack, int value)
{
    if (stack == NULL)
    {
        return 1;
    }

    struct node_t *temp;
    temp = malloc(sizeof(struct node_t));
    if (temp == NULL)
    {
        return 2;
    }

    temp->data = value;
    temp->next = stack->head;

    stack->head = temp;
    return 0;
}

int stack_init(struct stack_t **stack)
{
    if(stack == NULL)
    {
        return 1;
    }

    *(stack) = malloc(sizeof(struct stack_t));
    if(*stack == NULL)
    {
        return 2;
    }

    (*stack)->head = NULL;
    return 0;
}
