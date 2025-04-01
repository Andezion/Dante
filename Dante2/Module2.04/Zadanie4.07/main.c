#include "array.h"
#include <stdio.h>

int main()
{
    struct array_t a;

    int number;
    int error;
    int pointer = 0;

    printf("Enter: ");
    error = scanf("%i", &number);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(number <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    error=array_create(&a, number);
    if(error != 0)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int i = 0;
    int temporary_shit = 1;
    struct array_t odd, even;
    printf("Enter: ");
    while(temporary_shit != 0)
    {

        error = scanf("%i", &temporary_shit);
        if(error != 1)
        {
            array_destroy(&a);
            printf("Incorrect input");
            return 1;
        }
        if(i == 0 && temporary_shit == 0)
        {
            array_destroy(&a);
            printf("Not enough data available");
            return 3;
        }
        if(a.size == a.capacity / 2)
        {
            error = array_create(&odd, number);
            if(error != 0)
            {
                array_destroy(&a);
                printf("Failed to allocate memory");
                return 8;
            }
            else
            {
                array_destroy(&odd);
            }
        }

        if(a.size > number)
        {
            printf("Buffer is full\n");
        }

        error = array_push_back(&a, temporary_shit);
        if(error == 1)
        {
            array_destroy(&a);
            printf("Incorrect input");
            return 1;
        }
        if(error == 2)
        {
            pointer++;
        }
        if(a.size > number || pointer == 2)
        {
            printf("Buffer is full\n");
        }
        i++;
    }

    error = array_separate(&a, &odd, &even);
    if(error == -1 || error == 0)
    {
        array_destroy(&a);
        printf("Failed to allocate memory");
        return 8;
    }
    else if(error == 1)
    {
        array_display(&odd);

        printf("\nBuffer is empty");
        array_destroy(&a);
        array_destroy(&odd);
    }
    else if(error == 2)
    {
        printf("Buffer is empty\n");
        array_display(&even);

        array_destroy(&a);
        array_destroy(&even);
    }
    else
    {
        array_display(&odd);
        printf("\n");
        array_display(&even);

        array_destroy(&a);
        array_destroy(&even);
        array_destroy(&odd);
    }

    return 0;
}
