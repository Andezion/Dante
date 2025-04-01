#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"

int main()
{
    int capacity;
    printf("Enter buffer capacity: ");

    int check1 = scanf("%i", &capacity);
    if (check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(capacity <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct circular_buffer_t *buffer;
    int check2 = circular_buffer_create_struct(&buffer, capacity);
    if (check2 != 0)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int number = -1;
    int value;
    int err_code;

    while (number != 0)
    {
        printf("Enter your number: ");

        int check3 = scanf("%i", &number);
        if (check3 != 1)
        {
            printf("Incorrect input");

            while(getchar() != '\n');

            circular_buffer_destroy_struct(&buffer);
            return 1;
        }

        if(number == 0)
        {
            break;
        }
        else if(number == 1)
        {
            printf("Enter number: ");
            int number1 = scanf("%i", &value);
            if (number1 != 1)
            {
                printf("Incorrect input");

                while(getchar() != '\n');

                circular_buffer_destroy_struct(&buffer);
                return 1;
            }
            int check4 = circular_buffer_push_back(buffer, value);
            if (check4 != 0)
            {

            }
        }
        else if(number == 2)
        {
            int check5 = circular_buffer_pop_back(buffer, &err_code);
            if (err_code != 0)
            {
                if (err_code != 0)
                {
                    printf("Buffer is empty\n");
                }
            }
            else
            {
                printf("%i\n",check5);
            }
        }
        else if(number == 3)
        {
            int check5 = circular_buffer_pop_front(buffer, &err_code);
            if (err_code != 0)
            {
                if (err_code != 0)
                {
                    printf("Buffer is empty\n");
                }
            }
            else
            {

                printf("%i\n", check5);
            }
        }
        else if(number == 4)
        {
            if (circular_buffer_empty(buffer))
            {
                printf("Buffer is empty\n");
                continue;
            }
            circular_buffer_display(buffer);
            printf("\n");
        }
        else if(number == 5)
        {
            if (circular_buffer_empty(buffer))
            {
                printf("%s\n", "1");
            }
            else
            {
                printf("%s\n", "0");
            }
        }
        else if(number == 6)
        {
            if (circular_buffer_full(buffer))
            {
                printf("%s\n", "1");
            }
            else
            {
                printf("%s\n", "0");
            }
        }
        else
        {
            printf("Incorrect input data\n");
            continue;

        }
    }

    circular_buffer_destroy_struct(&buffer);
    free(buffer);

    return 0;
}
