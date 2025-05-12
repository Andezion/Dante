#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    struct linked_list_t *ll = ll_create();
    if (ll == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int err_code;
    while(1)
    {
        int input;
        printf("Enter number: ");
        err_code = scanf("%i", &input);
        if (err_code != 1)
        {
            printf("Incorrect input");

            ll_clear(ll);
            free(ll);

            return 1;
        }

        int test, value, index;

        if (input == 0)
        {
            break;
        }
        else if (input == 1)
        {
            printf("Provide number: ");
            err_code = scanf("%i", &value);
            if (err_code != 1)
            {
                printf("Incorrect input");

                ll_clear(ll);
                free(ll);

                return 1;
            }
            test = ll_push_back(ll, value);
            if (test == 2)
            {
                printf("Failed to allocate memory");

                ll_clear(ll);
                free(ll);

                return 8;
            }
        }
        else if (input == 2)
        {
            value = ll_pop_back(ll, &err_code);
            if (err_code == 1)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("%i\n", value);
            }
        }
        else if (input == 3)
        {
            printf("Enter number: ");
            err_code = scanf("%i", &value);
            if (err_code != 1)
            {
                printf("Incorrect input");

                ll_clear(ll);
                free(ll);

                return 1;
            }
            test = ll_push_front(ll, value);
            if (test == 2)
            {
                printf("Failed to allocate memory");

                ll_clear(ll);
                free(ll);

                return 8;
            }
        }
        else if (input == 4)
        {
            value = ll_pop_front(ll, &err_code);
            if (err_code == 1)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("%i\n", value);
            }
        }
        else if (input == 5)
        {
            printf("Enter number: ");
            err_code = scanf("%i", &value);
            if (err_code != 1)
            {
                printf("Incorrect input");

                ll_clear(ll);
                free(ll);

                return 1;
            }

            printf("Enter index: ");
            err_code = scanf("%i", &index);
            if (err_code != 1)
            {
                printf("Incorrect input");

                ll_clear(ll);
                free(ll);

                return 1;
            }
            test = ll_insert(ll, index, value);
            if (test == 2)
            {
                printf("Failed to allocate memory");

                ll_clear(ll);
                free(ll);

                return 8;
            }
            if (test == 1)
            {
                printf("Index out of range\n");
            }
        }
        else if (input == 6)
        {
            if (!ll_is_empty(ll))
            {
                printf("Enter index: ");
                err_code = scanf("%i", &index);
                if (err_code != 1)
                {
                    printf("Incorrect input");

                    ll_clear(ll);
                    free(ll);

                    return 1;
                }
                value = ll_remove(ll, index, &err_code);
                if (err_code == 1)
                {
                    printf("Index out of range\n");
                }
                else
                {
                    printf("%i\n", value);
                }
            }
            else
            {
                printf("List is empty\n");
            }
        }
        else if (input == 7)
        {
            value = ll_back(ll, &err_code);
            if (err_code == 1)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("%i\n", value);
            }
        }
        else if (input == 8)
        {
            value = ll_front(ll, &err_code);
            if (err_code == 1)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("%i\n", value);
            }
        }
        else if (input == 9)
        {
            printf("%i\n", ll_is_empty(ll));
        }
        else if (input == 10)
        {
            printf("%i\n", ll_size(ll));
        }
        else if (input == 11)
        {
            ll_clear(ll);
        }
        else if (input == 12)
        {
            if (!ll_is_empty(ll))
            {
                printf("Enter index: ");
                err_code = scanf("%i", &index);
                if (err_code != 1)
                {
                    printf("Incorrect input");

                    ll_clear(ll);
                    free(ll);

                    return 1;
                }

                value = ll_at(ll, index, &err_code);
                if (err_code == 1)
                {
                    printf("Index out of range\n");
                }
                else
                {
                    printf("%i\n", value);
                }
            }
            else
            {
                printf("List is empty\n");
            }
        }
        else if (input == 13)
        {
            if (!ll_is_empty(ll))
            {
                for (index = 0; index < ll_size(ll); index++)
                {
                    value = ll_at(ll, index, &err_code);
                    if (err_code == 0)
                    {
                        printf("%i ", value);
                    }
                }
                printf("\n");
            }
            else
            {
                printf("List is empty\n");
            }
        }
        else
        {
            printf("Incorrect input data\n");
        }
    }

    ll_clear(ll);
    free(ll);

    return 0;
}
