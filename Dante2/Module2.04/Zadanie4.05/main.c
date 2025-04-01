#include <stdio.h>
#include <stdlib.h>

int* create_array_int(int N);
int* copy_array_int(const int* ptr, int N);
void display_array_int(const int* ptr, int N);

int main()
{
    int num;
    printf("Enter: ");

    int check = scanf("%i",&num);
    if(!check)
    {
        printf("Incorrect input");
        return 1;
    }
    if(num <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int *array = create_array_int(num);
    if(!array)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    for(int i = 0; i < num; i++)
    {
        check = scanf("%i",(array + i));
        if(!check)
        {
            free(array);
            printf("Incorrect input");
            return 1;
        }
    }

    int *new = copy_array_int(array, num);
    if(!new)
    {
        free(array);
        printf("Failed to allocate memory");
        return 8;
    }

    display_array_int(array, num);
    printf("\n");
    display_array_int(new, num);

    free(array);
    free(new);
    return 0;
}

int* create_array_int(int N)
{
    if(N <= 0)
    {
        return NULL;
    }

    int *array = malloc(sizeof(int) * N);
    if(!array)
    {
        return NULL;
    }

    return array;
}

int* copy_array_int(const int* ptr, int N)
{
    if(ptr == NULL || N <= 0)
    {
        return NULL;
    }

    int *copy = malloc(sizeof(int) * N);
    if(!copy)
    {
        return NULL;
    }

    for(int i = 0; i < N; i++)
    {
        *(copy + i) = *(ptr + i);
    }

    return copy;
}

void display_array_int(const int* ptr, int N)
{
    if(ptr == NULL || N <= 0)
    {
        return;
    }

    for(int i = 0; i < N; i++)
    {
        printf("%i ",*(ptr + i));
    }
}
