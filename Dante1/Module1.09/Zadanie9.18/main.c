#include <stdio.h>
#include "vector_utils.h"

int counter(int tab[], int size, int num)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(num == tab[i])
        {
            count++;
        }
    }

    return count;
}

int freq_sort(int tab[], int size)
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
            int to_check1 = counter(tab, size, tab[j]);
            int to_check2 = counter(tab, size, tab[j + 1]);

            if (to_check1 < to_check2 || (to_check1 == to_check2 && tab[j] > tab[j + 1]))
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
    int size = read_vector(tab,150,-1);
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

    int result = freq_sort(tab,size);
    if(result != 0)
    {
        printf("Incorrect input data\n");
        return 0;
    }

    printf("\n");

    display_vector(tab,size);

    return 0;
}
