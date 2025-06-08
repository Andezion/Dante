#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int counter(int num)
{
    int count = 0;

    for(int i = 1; i <= abs(num); i++)
    {
        if(num % i == 0)
        {
            count++;
        }
    }

    return count;
}

int sort_by_dividers(int tab[], int size)
{
    if (tab == NULL || size <= 0)
    {
        return 1;
    }

    for (int i = 0; i == 0;)
    {
        i = 1;

        for (int j = 0; j < size - 1; j++)
        {
            int to_check1 = counter(tab[j]);
            int to_check2 = counter(tab[j + 1]);

            if (to_check1 > to_check2 || (to_check1 == to_check2 && tab[j] > tab[j + 1]))
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;

                i = 0;
            }
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

    int result = sort_by_dividers(tab,size);
    if(result != 0)
    {
        printf("Incorrect input data\n");
        return 0;
    }

    printf("\n");

    display_vector(tab,size);

    return 0;
}
