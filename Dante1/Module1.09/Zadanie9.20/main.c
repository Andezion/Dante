#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int counter(int num)
{
    int count = 0;

    num = abs(num);
    while (num != 0)
    {
        int temp = num % 10;
        count = count + temp;
        num = num / 10;
    }

    return count;
}

int sort_by_sum(int tab[], int size)
{
    if (tab == NULL || size <= 0)
    {
        return 1;
    }

    for (int sorted = 0; sorted == 0;)
    {
        sorted = 1;

        for (int j = 0; j < size - 1; j++)
        {
            int var1 = counter(tab[j]);
            int var2 = counter(tab[j + 1]);

            if (var1 > var2 || (var1 == var2 && tab[j] > tab[j + 1]))
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;

                sorted = 0;
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

    int result = sort_by_sum(tab,size);
    if(result != 0)
    {
        printf("Incorrect input data\n");
        return 0;
    }

    printf("\n");

    display_vector(tab,size);

    return 0;
}
