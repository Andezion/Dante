#include <stdio.h>
#include "vector_utils.h"

//от блять простое же задание, но зачем так его усложнять???? 43550498234 доп проверок и прочего боЖЕЕЕЕЕЕЕЕЕЕ

int main()
{
    int tab[1000];
    int size = 0;
    int to_find;
    int error;

    printf("Enter: ");
    for(int i = 0; i < 1000; i++)
    {
        error = scanf("%i",(tab + i));
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(*(tab + i) == 0)
        {
            break;
        }
        size++;
    }
    if(size > 100)
    {
        size = 100;
    }
    if (size == 0)
    {
        printf("Not enough data available");
        return 3;
    }

    printf("Enter number: ");
    error = scanf("%i", &to_find);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int index = find(tab, size, to_find);
    int found = 0;

    while (index != -1)
    {
        printf("%i ", index);
        found = 1;
        index = find(NULL, 0, to_find);
    }

    if (!found)
    {
        printf("Nothing to show");
    }

    return 0;
}
