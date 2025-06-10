#include <stdio.h>
#include "vector_utils.h"

int find_min(const int* tab, int size, int *min);

int main()
{
    int tab[100] = { 0 };
    printf("Enter: ");

    int size = read_vector(tab, 100, -1);
    if(size == -1)
    {
        printf("Incorrect input");
        return 1;
    }
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

    int min;
    int check = find_min(tab,size, &min);
    if(check == 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%i ",min);

    return 0;
}

int find_min(const int* tab, int size, int *min)
{
    if(tab == NULL || size <= 0 || min == NULL)
    {
        return 1;
    }
    if(size == 1)
    {
        *min = *(tab + 0);
        return 0;
    }

    int mina = 10000;
    for(int i = 0; i < size; i++)
    {
        if(*(tab + i) < mina)
        {
            mina = *(tab + i);
        }
    }

    *min = mina;

    return 0;
}
