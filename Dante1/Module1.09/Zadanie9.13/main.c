#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int sort_negative_asc_positive_desc(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < size; i++)
    {
        int pointer = 0;
        for(int j = 0; j < size - 1; j++)
        {
            if(tab[j] > tab[j + 1])
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

    int temp = 0;
    for(int i = 0; i < size; i++)
    {
        if(tab[i] < 0)
        {
            temp++;
        }
    }

    for(int i = temp; i < size; i++)
    {
        int pointer = 0;
        for(int j = temp; j < size - 1; j++)
        {
            if(tab[j] < tab[j + 1])
            {
                int temp1 = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp1;
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
    //printf("%i\n",size);
    if(size == -2 || size == -1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }
    if(size > 150)
    {
        size = 150;
    }

    while(getchar() != '\n');

    printf("\n");

    int result = sort_negative_asc_positive_desc(tab, size);
    if(result != 0)
    {
        printf("Incorrect input data\n");
        return 0;
    }

    printf("\n");

    display_vector(tab,size);

    return 0;
}
