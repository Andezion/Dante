#include <stdio.h>
#include <stdlib.h>

short *create_array_short(int N);
short *concatenate_arrays_short(const short *a1, int size1, const short *a2, int size2, int *err_code);
int sort_short(short* tab, int size);
void display_vector_short(const short* tab, int size);

int main()
{
    int error;

    int size1;
    printf("Enter: ");

    error = scanf("%i",&size1);
    if(!error)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size1 <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    short *a1 = create_array_short(size1);
    if(a1 == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Enter: ");
    for(int i = 0; i < size1; i++)
    {
        error = scanf("%hi",(a1 + i));
        if(!error)
        {
            printf("Incorrect input");
            free(a1);
            return 1;
        }
    }

    int size2;
    printf("Enter: ");

    error = scanf("%i",&size2);
    if(!error)
    {
        printf("Incorrect input");
        free(a1);
        return 1;
    }
    if(size2 <= 0)
    {
        printf("Incorrect input data");
        free(a1);
        return 2;
    }

    short *a2 = create_array_short(size2);
    if(a2 == NULL)
    {
        printf("Failed to allocate memory");
        free(a1);
        return 8;
    }
    printf("Enter: ");
    for(int i = 0; i < size2; i++)
    {
        error = scanf("%hi",(a2 + i));
        if(!error)
        {
            printf("Incorrect input");
            free(a1);
            free(a2);
            return 1;
        }
    }

    int err_code;
    short *tab = concatenate_arrays_short(a1, size1, a2, size2, &err_code);
    if(tab == NULL)
    {
        printf("Failed to allocate memory");
        free(a1);
        free(a2);
        return 8;
    }

    error = sort_short(tab, size1 + size2);
    if(error == 1)
    {
        printf("Incorrect input");
        free(a1);
        free(a2);
        return 1;
    }

    printf("\n");
    display_vector_short(tab, size1 + size2);

    free(a1);
    free(a2);
    free(tab);
    return 0;
}

short *concatenate_arrays_short(const short *a1, int size1, const short *a2, int size2, int *err_code)
{
    if(a1 == NULL || a2 == NULL || size1 <= 0 || size2 <= 0)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    int size = size1 + size2;
    short *array = malloc(sizeof(short) * size);
    if(array == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return NULL;
    }

    for(int i = 0; i < size1; i++)
    {
        *(array + i) = *(a1 + i);
    }

    for(int i = 0; i < size2; i++)
    {
        *(array + size1 + i) = *(a2 + i);
    }

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return array;
}

void display_vector_short(const short* tab, int size)
{
    if(tab == NULL || size <= 0)
    {
        return;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%i ",*(tab + i));
    }
}

short *create_array_short(int N)
{
    if(N <= 0)
    {
        return NULL;
    }

    short *array = malloc(sizeof(short) * N);
    if(array == NULL)
    {
        return NULL;
    }

    return array;
}

int sort_short(short* tab, int size)
{
    if(tab == NULL || size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < size - 1; i++)
    {
        int point = 0;
        for(int j = 0; j < size - 1; j++)
        {
            if(*(tab + j) > *(tab + j + 1))
            {
                short temp = *(tab + j);
                *(tab + j) = *(tab + j + 1);
                *(tab + j + 1) = temp;
                point = 1;
            }
        }
        if(point == 0)
        {
            break;
        }
    }

    return 0;
}
