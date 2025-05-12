#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int stack_push(struct stack_t **stack, char *value)
{
    if (stack == NULL || value == NULL)
    {
        return 1;
    }

    struct stack_t *working_on_that = malloc(sizeof(struct stack_t));
    if (working_on_that == NULL)
    {
        return 2;
    }

    if (!*stack)
    {
        working_on_that->sentence = value;
        *stack = working_on_that;

        (*stack)->prev = NULL;
    }
    else
    {
        working_on_that->prev = *stack;
        working_on_that->sentence = value;

        *stack = working_on_that;
    }

    return 0;
}

int stack_load(struct stack_t **stack, const char *filename)
{
    if (stack == NULL || filename == NULL || *stack)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        return 2;
    }

    char *text = malloc(sizeof(char));
    if (text == NULL)
    {
        fclose(file);
        return 3;
    }

    int length = 0;
    char *buffer = NULL;
    for (; !feof(file); )
    {
        length = length + 1;
        buffer = realloc(text, sizeof(char) * (length + 1));

        if (buffer != NULL)
        {
            text = buffer;

            char c = (char)fgetc(file);

            if (c == '.')
            {
                *(text + length - 1) = '.';
                *(text + length) = '\0';

                if (stack_push(stack, text) > 0)
                {
                    stack_destroy(stack);
                    free(text);
                    fclose(file);

                    return 3;
                }
                text = (char *) malloc(sizeof(char));
                length = 0;
            }
            else
            {
                *(text + length - 1) = c;
            }
        }
        else
        {
            stack_destroy(stack);
            free(text);
            fclose(file);

            return 3;
        }
    }

    free(text);
    fclose(file);
    return 0;
}

int stack_save(const struct stack_t *stack, const char *filename)
{
    if (stack == NULL || filename == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        return 2;
    }

    for (; stack;)
    {
        fprintf(file, "%s", stack->sentence);
        stack = stack->prev;
    }

    fclose(file);
    return 0;
}

char *stack_pop(struct stack_t **stack, int *err_code)
{
    if (stack == NULL || *stack == NULL)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    char *text = (*stack)->sentence;

    struct stack_t *working_on_that = *stack;
    *stack = working_on_that->prev;

    free(working_on_that);

    if (err_code)
    {
        *err_code = 0;
    }
    return text;
}

void stack_destroy(struct stack_t **stack)
{
    if (stack != NULL)
    {
        struct stack_t *working_on_that;

        for (; *stack;)
        {
            free((*stack)->sentence);
            working_on_that = (*stack)->prev;

            free(*stack);
            *stack = working_on_that;
        }

        *stack = NULL;
    }
}
