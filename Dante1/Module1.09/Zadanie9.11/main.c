#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_by_abs(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int pointer = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (abs(tab[j]) > abs(tab[j + 1]))
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                pointer = 1;
            }
        }
        if(pointer == 0)
        {
            break;
        }
    }
    return 0;
}

int main()
{
    int tab[150];

    printf("Enter: ");
    int size = read_vector(tab,150,0);
    if(size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }

    int result = sort_by_abs(tab,size);
    if(result != 0)
    {
        printf("Incorrect input data\n");
        return 0;
    }

    printf("\n");

    display_vector(tab,size);

    return 0;
}
