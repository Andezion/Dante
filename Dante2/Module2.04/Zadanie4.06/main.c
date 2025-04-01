#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
    int num;

    printf("Enter: ");
    int check = scanf("%i",&num);
    if(!check)
    {
        printf("Incorrect input");
        return 1;
    }
    if(num == 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct array_t a;
    check = array_create(&a, num);
    if(check == 1)
    {
        printf("Incorrect input data");
        return 2;
    }
    if(check == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int number = 1;
    int pointer = 0;
    printf("Enter: ");

    while(number != 0)
    {
        check = scanf("%i",&number);
        if(!check)
        {
            printf("Incorrect input");
            array_destroy(&a);
            return 1;
        }
        if(number != 0)
        {
            pointer = 1;
        }
        check = array_push_back(&a, number);
        if(check == 1)
        {
            printf("Incorrect input data");
            return 2;
        }
        if(check == 2)
        {
            break;
        }
    }
    if(pointer == 0)
    {
        printf("Buffer is empty\n");
        array_destroy(&a);
        return 0;
    }
    if(a.size == a.capacity)
    {
        printf("Buffer is full\n");
    }

    array_display(&a);
    array_destroy(&a);

    return 0;
}

