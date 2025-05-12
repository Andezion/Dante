#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_display(const struct stack_t *stack)
{
    if (stack == NULL)
    {
        return;
    }

    struct node_t *working_on_that = stack->head;
    for (; working_on_that != NULL;)
    {
        printf("%i ", working_on_that->data);

        working_on_that = working_on_that->next;
    }
}

int stack_pop(struct stack_t *stack, int *err_code)
{
    if (stack != NULL && stack->head != NULL)
    {
        int result_number = stack->head->data;
        struct node_t *helper = stack->head->next;

        free(stack->head);
        stack->head = helper;

        if (err_code == NULL)
        {
            return result_number;
        }
        *err_code = 0;
        return result_number;
    }
    else
    {
        if (err_code == NULL)
        {
            return 1;
        }
        *err_code = 1;
        return 1;
    }
}

int stack_init(struct stack_t **stack)
{
    if (stack != NULL)
    {
        struct stack_t *out_working_place = malloc(sizeof(struct stack_t));
        if (out_working_place != NULL)
        {
            out_working_place->head = NULL;
            *stack = out_working_place;

            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

int stack_empty(const struct stack_t *stack)
{
    if (stack == NULL)
    {
        return 2;
    }

    if (stack->head != NULL)
    {
        return 0;
    }

    return 1;
}

int stack_push(struct stack_t *stack, int value)
{
    if (stack != NULL)
    {
        struct node_t *working_on_that = malloc(sizeof(struct node_t));
        if (working_on_that != NULL)
        {
            working_on_that->data = value;
            working_on_that->next = stack->head;

            stack->head = working_on_that;

            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

void stack_destroy(struct stack_t **stack)
{
    if (stack == NULL || *stack == NULL)
    {
        return;
    }

    struct stack_t *working_on_that = *stack;
    struct node_t *our_temporary_helper;

    for (; working_on_that->head != NULL;)
    {
        our_temporary_helper = working_on_that->head->next;
        free(working_on_that->head);

        working_on_that->head = our_temporary_helper;
    }

    free(working_on_that);
    *stack = NULL;
}
