#include <stdio.h>
#include <stdlib.h>

float* create_array(int N)
{
    if(N <= 0)
    {
        return NULL;
    }

    float *array = malloc(sizeof(float) * N);
    if(!array)
    {
        return NULL;
    }

    return array;
}

int main()
{
    int num;
    printf("Enter: ");
    int check = scanf("%i",&num);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(num <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    float *array = create_array(num);
    if(array == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    for(int i = 0; i < num; i++)
    {
        int check1 = scanf("%f",&*(array + i));
        if(check1 != 1)
        {
            printf("Incorrect input");
            free(array);
            return 1;
        }
    }

    for(int i = num - 1; i >= 0; i--)
    {
        printf("%f ",*(array + i));
    }

    free(array);
    return 0;
}
