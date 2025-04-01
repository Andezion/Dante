#include <stdio.h>
#include "vector.h"

int main()
{
    int error;
    int size;
    printf("Enter your: ");

    error = scanf("%i", &size);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if (size <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct vector_t *a;
    error = vector_create_struct(&a, size);
    if (error == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    while(1)
    {
        int number;
        printf("What to do: ");

        error = scanf("%i", &number);
        if (error != 1)
        {
            printf("Incorrect input");
            vector_destroy_struct(&a);
            return 1;
        }

        if (number < 0 || number > 2)
        {
            printf("Incorrect input data\n");
        }
        else
        {
            if (number == 1)
            {
                printf("Enter numbers: ");
                int num = 1;

                while (1)
                {
                    error = scanf("%i", &num);
                    if (error != 1)
                    {
                        printf("Incorrect input");
                        vector_destroy_struct(&a);
                        return 1;
                    }

                    if (num == 0)
                    {
                        break;
                    }

                    error = vector_push_back(a, num);
                    if (error == 2)
                    {
                        printf("Failed to allocate memory\n");
                        break;
                    }
                }

                if (a->size == 0)
                {
                    printf("Buffer is empty");
                    continue;
                }
                vector_display(a);
                printf("\n");
            }

            if (number == 2)
            {
                int num2 = 1;
                printf("Enter your numbers: ");

                while (num2 != 0)
                {
                    error = scanf("%i", &num2);
                    if (error != 1)
                    {
                        printf("Incorrect input");
                        vector_destroy_struct(&a);
                        return 1;
                    }
                    if (num2 != 0)
                    {
                        vector_erase(a, num2);
                    }
                    else
                    {
                        break;
                    }
                }

                if (a->size != 0)
                {
                    vector_display(a);
                    printf("\n");
                }
                else
                {
                    printf("Buffer is empty\n");
                    continue;
                }
            }

            if (number != 0)
            {
                continue;
            }
            break;
        }
    }

    vector_destroy_struct(&a);
    return 0;
}
