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
    int err_code;
    unsigned int num;

    int pick = -1;
    for (;pick != 0;)
    {
        printf("Enter: ");
        error = scanf("%i", &pick);
        if (error != 1)
        {
            return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
        }

        switch (pick)
        {
            case 0:
                break;
            case 1:
                printf("Enter: ");
                error = scanf("%i", &number);
                if (error != 1)
                {
                    return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
                }

                error = dll_push_back(stack, number);
                if (error != 0)
                {
                    return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
                }

                break;
            case 2:
                error = dll_pop_back(stack, &err_code);
                if (err_code != 0)
                {
                    printf("List is empty\n");
                }
                else
                {
                    printf("%i\n", error);
                }

                break;
            case 3:
                printf("Enter: ");
                error = scanf("%i", &number);
                if (error != 1)
                {
                    return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
                }

                error = dll_push_front(stack, number);
                if (error != 0)
                {
                    return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
                }

                break;
            case 4:
                error = dll_pop_front(stack, &err_code);
                if (err_code != 0)
                {
                    printf("List is empty\n");
                }
                else
                {
                    printf("%i\n", error);
                }

                break;
            case 5:
                printf("Enter: ");
                error = scanf("%i", &number);
                if (error != 1)
                {
                    return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
                }

                printf("Enter: ");
                error = scanf("%u", &num);
                if (error != 1)
                {
                    return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
                }

                error = dll_insert(stack, num, number);
                if (error == 1)
                {
                    printf("Index out of range\n");
                }
                if (error == 2)
                {
                    return printf("Failed to allocate memory"), dll_clear(stack), free(stack), 8;
                }

                break;
            case 6:
                if (dll_is_empty(stack) != 1)
                {
                    printf("Enter: ");

                    error = scanf("%u", &num);
                    if (error != 1)
                    {
                        return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
                    }

                    error = dll_remove(stack, num, &err_code);
                    if (err_code == 0)
                    {
                        printf("%i\n", error);
                    }
                    else
                    {
                        printf("Index out of range\n");
                    }
                }
                else
                {
                    printf("List is empty\n");
                }

                break;
            case 7:
                error = dll_back(stack, &err_code);
                if (err_code == 0)
                {
                    printf("%i\n", error);
                }
                else
                {
                    printf("List is empty\n");
                }

                break;
            case 8:
                error = dll_front(stack, &err_code);
                if (err_code == 0)
                {
                    printf("%i\n", error);
                }
                else
                {
                    printf("List is empty\n");
                }

                break;
            case 9:
                if (dll_is_empty(stack) != 1)
                {
                    printf("0\n");
                }
                else
                {
                    printf("1\n");
                }

                break;
            case 10:
                printf("%i\n", dll_size(stack));

                break;
            case 11:
                dll_clear(stack);

                break;
            case 12:
                if (dll_is_empty(stack) == 1)
                {
                    printf("List is empty\n");
                }
                else
                {
                    printf("Enter: ");
                    error = scanf("%u", &num);

                    if (error != 1)
                    {
                        return printf("Incorrect input"), dll_clear(stack), free(stack), 1;
                    }

                    error = dll_at(stack, num, NULL);
                    printf("%i\n", error);
                }

                break;
            case 13:
                if (dll_is_empty(stack) != 1)
                {
                    dll_display(stack);
                    printf("\n");
                }
                else
                {
                    printf("List is empty\n");
                }

                break;
            case 14:
                if (dll_is_empty(stack) != 1)
                {
                    dll_display_reverse(stack);
                    printf("\n");
                }
                else
                {
                    printf("List is empty\n");
                }

                break;
            default:
                printf("Incorrect input data\n");
                break;
        }
    }

    dll_clear(stack);
    free(stack);
    return 0;
}
