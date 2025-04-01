#include <stdio.h>
#include <stdlib.h>

int create_array_int(int **ptr, int N);
void destroy_array_int(int **ptr);

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
    if(num < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int *array;
    check = create_array_int(&array, num);
    if(check == 1)
    {
        printf("Incorrect input data");
        return 2;
    }
    if(check == 2)
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
            printf("Incorrect input");
            destroy_array_int(&array);
            return 1;
        }
    }


    for(int i = num - 1; i >= 0; i--)
    {
        printf("%i ",*(array + i));
    }

    destroy_array_int(&array);
    return 0;
}

int create_array_int(int **ptr, int N)
{
    if(ptr == NULL || N <= 0)
    {
        return 1;
    }

    int *array = malloc(sizeof(int) * N);
    if(array == NULL)
    {
        return 2;
    }

    *ptr = array;

    return 0;
}

void destroy_array_int(int **ptr)
{
    if(ptr != NULL && *ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
}
