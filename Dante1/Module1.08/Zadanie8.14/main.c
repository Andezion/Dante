#include <stdio.h>

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <=0 )
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (scanf("%d",&vec[i]) != 1)
        {
            return 1;
        }
        if (vec[i] == stop_value)
        {
            break;
        }
        count++;
    }
    return count;
}

int is_palindrom_rec(const int tab[], int start_index, int end_index)
{
    if(start_index < 0 || end_index < 0)
    {
        return -1;
    }
    if(start_index >= end_index)
    {
        return 1;
    }
    if(tab[start_index] == tab[end_index])
    {
        return is_palindrom_rec(tab,start_index + 1, end_index - 1);
    }
    return 0;
}

int main()
{
    int vector[100];

    printf("Enter: ");

    int size = read_vector(vector, 100, -1);
    if(size == 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size <= 1)
    {
        printf("\nNot enough data available\n");
        return 2;
    }

    int res = is_palindrom_rec(vector, 0, size - 1);
    if(res == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
