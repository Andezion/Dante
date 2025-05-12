#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments");
        return 9;
    }

    int error;
    struct stack_t *stack;
    for (int i = 1; i < argc; i++)
    {
        error = stack_load(&stack, *(argv + i));
        if (error == 2)
        {
            printf("Couldn't open file %s\n", *(argv + i));
            continue;
        }
        if (error == 3)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        if (error == 1)
        {
            printf("Incorrect input\n");
            continue;
        }

        error = stack_save(stack, *(argv + i));
        if (error != 1)
        {
            if (error == 2)
            {
                printf("Couldn't create file\n");
                stack_destroy(&stack);
                return 5;
            }
            else
            {
                printf("File %s saved\n", *(argv + i));
                stack_destroy(&stack);
            }
        }
        else
        {
            printf("Incorrect input\n");
            stack_destroy(&stack);
            continue;
        }
    }

    return 0;
}
