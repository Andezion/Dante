#include <stdio.h>
#include "vector_utils.h"

int complex_sort(int tab[], int size)
{
    if (tab == NULL || size <= 0 || size % 2 != 0)
    {
        return 1;
    }

    for (int i = 0; i < size - 2; i = i + 2)
    {
        for (int j = 0; j < size - i - 2; j = j + 2)
        {
            double to_check1 = tab[j];
            double to_check2 = tab[j + 2];
            double second_check1 = tab[j + 1];
            double second_check2 = tab[j + 3];

            if (to_check1 > to_check2 || (to_check1 == to_check2 && second_check1 < second_check2))
            {
                int temp = tab[j];
                tab[j] = tab[j + 2];
                tab[j + 2] = temp;

                temp = tab[j + 1];
                tab[j + 1] = tab[j + 3];
                tab[j + 3] = temp;
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
        printf("\nIncorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("\nNot enough data available");
        return 3;
    }

    int result = complex_sort(tab,size);
    if(result != 0)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    printf("\n");

    display_vector(tab,size);

    return 0;
}
