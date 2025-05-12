#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

size_t my_getline(FILE *stream, char **buf, size_t *size)
{
    size_t len = 0;
    int c;
    if (*buf == NULL)
    {
        *size = 128;
        *buf = malloc(*size);
        if (*buf == NULL)
        {
            return -1;
        }
    }
    while ((c = fgetc(stream)) != EOF && c != '\n')
    {
        if (len + 1 >= *size)
        {
            *size *= 2;
            char *new_buf = realloc(*buf, *size);
            if (new_buf == NULL)
            {
                return -1;
            }
            *buf = new_buf;
        }
        *((*buf) + len++) = c;
    }
    *((*buf) + len) = '\0';
    return len;
}

int main()
{
    int error;
    struct stack_t *stack;
    error = stack_init(&stack);

    if (error != 0)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    char *text = NULL;
    size_t size_of = 0;
    printf("Enter: ");

    error = my_getline(stdin, &text, &size_of);
    if (error == -1)
    {
        printf("Incorrect text");

        free(text);

        return 1;
    }

    char *token = strtok(text, " \n");
    for (; token != NULL;)
    {
        if (isdigit(*(token + 0)) || (*(token + 0) == '-' && isdigit(*(token + 1))))
        {
            double value = atof(token);

            error = stack_push(stack, value);
            if (error != 0)
            {
                printf("Failed to allocate memory");

                stack_destroy(&stack);

                return 8;
            }
        }
        else if (what_operation_to_do_switch(*(token + 0)) && *(token + 1) == '\0')
        {
            int err_code;

            double arg2 = stack_pop(stack, &err_code);
            if (err_code != 0)
            {
                printf("Incorrect expression");

                stack_destroy(&stack);

                return 2;
            }

            double arg1 = stack_pop(stack, &err_code);
            if (err_code != 0)
            {
                printf("Incorrect expression");

                stack_destroy(&stack);

                return 2;
            }

            double result = what_to_do_switch(*(token + 0), arg1, arg2);
            error = stack_push(stack, result);
            if (error != 0)
            {
                printf("Failed to allocate memory");

                stack_destroy(&stack);

                return 8;
            }
        }
        else
        {
            printf("Incorrect text");

            stack_destroy(&stack);

            return 1;
        }

        token = strtok(NULL, " \n");
    }

    error = stack_size(stack);
    if (error != 1)
    {
        printf("Incorrect expression");

        stack_destroy(&stack);

        return 2;
    }

    int err_code;
    double result = stack_pop(stack, &err_code);
    if (err_code != 0)
    {
        printf("Incorrect expression");

        stack_destroy(&stack);

        return 2;
    }
    else
    {
        printf("%f\n", result);
    }

    stack_destroy(&stack);
    return 0;
}
