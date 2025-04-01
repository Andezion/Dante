#include <stdio.h>
#include <stdlib.h>

int *create_array_int(int N);
int histogram(const int *tab, int size, int **out, int *out_size, int *out_begin);

int main()
{
    int number;
    int error;

    printf("Enter: ");

    error = scanf("%i",&number);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(number <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }


    int *cheker = create_array_int(number);
    if(cheker == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    for(int i = 0; i < number; i++)
    {
        error = scanf("%i",(cheker + i));
        if(error != 1)
        {
            printf("Incorrect input");
            free(cheker);
            return 1;
        }
    }

    
    int out_begin = 0;;
    int out_size = 0;
    int *autism;

    error = histogram(cheker, number, &autism, &out_size, &out_begin);
    if(error == 1)
    {
        printf("Incorrect input");
        free(cheker);
        free(autism);
        return 1;
    }
    if(error == 2)
    {
        printf("Failed to allocate memory");
        free(cheker);
        free(autism);
        return 8;
    }

    for (int i = 0; i < out_size; i++)
    {
        printf("%i - %i\n", out_begin + i, *(autism + i));
    }

    free(cheker);
    free(autism);
    return 0;
}

int *create_array_int(int N)
{
    if(N <= 0)
    {
        return NULL;
    }

    int *array = malloc(N * sizeof(int));
    if(array == NULL)
    {
        return NULL;
    }
    return array;
}

int histogram(const int *tab, int size, int **out, int *out_size, int *out_begin)
{
    if(tab == NULL || size <= 0 || out == NULL || out_size == NULL || out_begin == NULL)
    {
        return 1;
    }

    int min = *(tab + 1);
    int max = *(tab + 0);

    for(int i = 0; i < size; i++)
    {
        if(*(tab + i) < min)
        {
            min = *(tab + i);
        }
        if(*(tab + i) > max)
        {
            max = *(tab + i);
        }
    }

    int temp = max - min + 1;

    *out_size = temp;
    *out_begin = min;

    *out = create_array_int(temp);
    if(*out == NULL)
    {
        return 2;
    }

    int *helper = *out;

    for(int i = 0; i < *out_size; i++)
    {
        *(helper + i) = 0;
    }

    int *some_shitty_helper = &size;
    for(int i = 0; i < *some_shitty_helper; i++)
    {
        int index = *(tab + i) - min;
        *(helper + index) = *(helper + index) + 1;
    }

    return 0;
}
