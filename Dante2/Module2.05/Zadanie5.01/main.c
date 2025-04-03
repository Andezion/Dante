#include <stdlib.h>
#include <stdio.h>

int main()
{
    int **array = (int **) malloc(sizeof(int *) * 10);
    if(array == NULL)
    {
       printf("Failed to allocate memory");
       return 8;
    }

    for(int i = 0; i < 10; i++)
    {
        *(array + i) = malloc(sizeof(int) * 10);
        if(*(array + i) == NULL)
        {
            printf("Failed to allocate memory");
            for(int j = 0; j < i; j++)
            {
                free(*(array + j));
            }
            free(array);
            return 8;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            *(*(array + i) + j) = (i + 1) * (j + 1);
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%4i", *(*(array + i) + j));
        }
        printf("\n");
    }

    for(int j = 0; j < 10; j++)
    {
        free(*(array + j));
    }
    free(array);
    return 0;
}
