#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <=0 )
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%i",&vec[i]);
        if (check != 1)
        {
            return -2;
        }
        if (vec[i] == stop_value)
        {
            break;
        }
        count++;
    }
    return count;
}

void display_vector(const int vec[], int size)
{
    if (vec == NULL || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%i ",vec[i]);
    }
}

void shuffle(int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return;
    }

    if(size == 1)
    {
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int j = rand() % (i + 1);

        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

int main()
{
    srand(time(NULL));

    int tab[101];

    printf("Enter: ");

    int size = read_vector(tab, 100, 0);
    if(size == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size == -2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size < 1)
    {
        printf("\nNot enough data available\n");
        return 2;
    }

    printf("\n");
    shuffle(tab, size);
    display_vector(tab,size);
    printf("\n");

    return 0;
}
