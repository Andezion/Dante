#include <stdio.h>
#include <stdlib.h>

void display_vector(const int* tab, int size);
int *create_array_int(int N);
int split(const int* tab, int size, int **unique, int *unique_size, int **rest, int *rest_size);

int main()
{

}

int split(const int* tab, int size, int **unique, int *unique_size, int **rest, int *rest_size)
{
    if(tab == NULL || size <= 0 || unique == NULL || unique_size == NULL || rest == NULL || rest_size == NULL)
    {
        return 1;
    }

    int temp_unique_size = 0;
    int temp_rest_size = 0;

    for(int i = 0; i < size; i++)
    {
        int temp = 0;
        for(int j = 0; j < size; j++)
        {
            if(*(tab + i) == *(tab + j))
            {
                temp++;
            }
        }

        if(temp == 1)
        {
            temp_unique_size++;
        }
        else
        {
            temp_rest_size++;
        }
    }

    *unique_size = temp_unique_size;
    *rest_size = temp_rest_size;

    int *temp_unique = create_array_int(*unique_size);
    if(temp_unique == NULL)
    {
        return 2;
    }

    int *temp_rest = create_array_int(*rest_size);
    if(temp_rest == NULL)
    {
        return 2;
    }

    int i1 = 0, j1 = 0;
    for(int i = 0; i < size; i++)
    {
        int temp = 0;
        for(int j = 0; j < size; j++)
        {
            if(*(tab + i) == *(tab + j))
            {
                temp++;
            }
        }

        if(temp == 1)
        {
            *(temp_unique + i1) = *(tab + i);
            i1++;
        }
        else
        {
            *(temp_rest + j1) = *(tab + i);
            j1++;
        }
    }

    *unique = temp_unique;
    *rest = temp_rest;

    free(temp_unique);
    free(temp_rest);
    return 0;
}

int *create_array_int(int N)
{
    if(N <= 0)
    {
        return NULL;
    }

    int *array = malloc(sizeof(int) * N);
    return array;
}

void display_vector(const int* tab, int size)
{
    if (tab == NULL || size <= 0)
    {
        return;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%i ",*(tab + i));
    }
}
