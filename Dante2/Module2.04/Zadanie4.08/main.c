#include <stdio.h>
#include "array.h"

int main()
{
    int size,error;

    printf("Enter: ");
    error = scanf("%i", &size);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct array_t *a;
    error = array_create_struct(&a, size);
    if(error == 1 || error == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    
    int choice;
    while(1)
    {
        while(getchar() != '\n');

        printf("Enter:");
        error = scanf("%i", &choice);
        if(error != 1)
        {
            printf("Incorrect input");
            array_destroy_struct(&a);
            return 1;
        }
        if(choice == 1)
        {
            int num;
            int counter = 0;
            printf("Enter:");

            do
            {
                error = scanf("%i", &num);
                if(error != 1)
                {
                    printf("Incorrect input");
                    array_destroy_struct(&a);
                    return 1;
                }
                if(counter >= a->capacity)
                {
                    printf( "Buffer is full\n");
                }
                if(num == 0 || counter == a->capacity)
                {
                    break;
                }
                if(num != 0)
                {
                    error = array_push_back(a, num);
                    if(error != 0)
                    {
                        printf("Incorrect input");
                        array_destroy_struct(&a);
                        return 1;
                    }
                    counter++;
                }
            }
            while(1);

            if(a->size == 0)
            {
                printf( "Buffer is empty\n");
            }
            else
            {
                array_display(a);
                printf("\n");
            }
        }
        else if(choice == 2)
        {
            int num;
            int counter = 0;
            printf("Enter: ");
            do
            {
                error=scanf("%i", &num);
                if(error != 1)
                {
                    printf("Incorrect input");
                    array_destroy_struct(&a);
                    return 1;
                }
                counter++;
                if(num == 0)
                {
                    break;
                }
                array_remove_item(a,num);
            }
            while(1);

            if (a->size != 0)
            {
                array_display(a);
                printf("\n");
            }
            else
            {
                printf("Buffer is empty\n");
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Incorrect input data\n");
        }
    }

    array_destroy_struct(&a);
    return 0;
}
