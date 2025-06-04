#include <stdio.h>

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

int set_union(const int first[], int size, const int second[], int size2, int dest[], int size3);
int set_intersection(const int first[], int size, const int second[], int size2, int dest[], int size3);
int set_difference(const int first[], int size, const int second[], int size2, int dest[], int size3);
int is_sorted(const int vec[], int size);

int main()
{
    int first[7] = {2, 3, 4, 5, 14, 15, 16};
    int second[7] = {1, 2, 3, 4, 5, 6, 7};
    int dest1[14];
    int dest2[14];

    int new1 = set_difference(first, 7, second, 7, dest1, 14);
    display_vector(dest1, new1);

    printf("\n");

    int new2 = set_intersection(first, 7, second, 7, dest2, 14);
    display_vector(dest2, new2);

    return 0;
}

int set_union(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if(first == NULL || size <= 0 || second == NULL || size2 <= 0 || size3 <= 0)
    {
        return -1;
    }
    if(size + size2 > size3)
    {
        return -2;
    }
    return 0;
}

int set_intersection(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if(first == NULL || size <= 0 || second == NULL || size2 <= 0 || size3 <= 0)
    {
        return -1;
    }
    if(size + size2 > size3)
    {
        return -1;
    }

    int index = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size2; j++)
        {
            if(first[i] == second[j])
            {
                dest[index] = first[i];
                index++;
                break;
            }
        }
    }

    for(int i = 0; i < index - 1; i++)
    {
        int point = 0;
        for(int j = 0; j < index - 1; j++)
        {
            if(dest[j] > dest[j + 1])
            {
                int temp = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp;
                point = 1;
            }
        }
        if(point == 0)
        {
            break;
        }
    }

    return index;
}

int set_difference(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if(first == NULL || size <= 0 || second == NULL || size2 <= 0 || size3 <= 0)
    {
        return -1;
    }
    if(size + size2 > size3)
    {
        return -1;
    }

    int index = 0;
    for(int i = 0; i < size; i++)
    {
        int point = 0;
        for(int j = 0; j < size2; j++)
        {
            if(first[i] == second[j])
            {
                point = 1;
                break;
            }
        }
        if(point == 0)
        {
            dest[index] = first[i];
            index++;
        }
    }

    for(int i = 0; i < size2; i++)
    {
        int point = 0;
        for(int j = 0; j < size; j++)
        {
            if(second[i] == first[j])
            {
                point = 1;
                break;
            }
        }
        if(point == 0)
        {
            dest[index] = second[i];
            index++;
        }
    }


    for(int i = 0; i < index - 1; i++)
    {
        int point = 0;
        for(int j = 0; j < index - 1; j++)
        {
            if(dest[j] > dest[j + 1])
            {
                int temp = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp;
                point = 1;
            }
        }
        if(point == 0)
        {
            break;
        }
    }

    return index;
}

int is_sorted(const int vec[], int size)
{
    if(vec == NULL || size <= 0)
    {
        return -1;
    }

    for(int i = 0; i < size - 1; i++)
    {
        if(vec[i] > vec[i + 1])
        {
            return 0;
        }
    }

    return 1;
}
