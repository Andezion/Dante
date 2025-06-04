#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <= 0)
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
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

int vector_difference(const int first[], int size, const int second[], int size2, int dst[], int size3)
{
    if(first == NULL || size <= 0 || second == NULL || size2 <= 0 || dst == NULL || size3 <= 0)
    {
        return -1;
    }

    int n = 0;
    for(int i = 0; i < size; i++)
    {
        int pointer = 0;
        for(int j = 0; j < size2; j++)
        {
            if(first[i] == second[j])
            {
                pointer = 1;
            }
        }
        if(pointer == 0)
        {
            dst[n] = first[i];
            n++;
        }
    }

    if(n > size3)
    {
        return -1;
    }

    return n;
}
int random_vector(const int src[], int size, int dst[], int size2)
{
    if(src == NULL || size <= 0 || dst == NULL || size2 <= 0 || size > size2)
    {
        return -1;
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        int random_index = rand() % size;
        dst[i] = src[random_index];
    }

    return size;
}

int main()
{
    int tab[150];

    printf("Enter: ");

    int size = read_vector(tab, 150, 0);
    if(size < 0)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 2;
    }

    int first[150];
    int second[150];

    int temp1 = random_vector(tab, size, first, size);
    if(temp1 == -1)
    {
        printf("Incorrect input");
        return 1;
    }

    int temp2 = vector_difference(tab, size, first, temp1, second, size);
    if(temp2 == -1)
    {
        printf("Incorrect input");
        return 1;
    }

    display_vector(first, temp1);
    printf("\n");
    if(temp2 > 0)
    {
        display_vector(second, temp2);
    }
    else
    {
        printf("Nothing to show");
    }

    return 0;
}
