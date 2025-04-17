#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"

int main()
{
    int error;
    func funcs[]= {comp_min, comp_max, comp_sum};

    int column, row;
    printf("Enter size: ");
    error = scanf("%i %i", &column, &row);
    if(error != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(column <= 0 || row <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int **array = malloc(row * sizeof(int *));
    if(array == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    for(int i = 0; i < row; i++)
    {
        *(array + i) = malloc(column * sizeof(int));
        if(*(array + i) == NULL)
        {
            printf("Failed to allocate memory");

            for(int j = 0; j < i; j++)
            {
                if(*(array + j) != NULL)
                {
                    free(*(array + j));
                }
            }
            free(array);

            return 8;
        }
    }

    printf("Enter your array:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            error = scanf("%i",(*(array + i) + j));
            if(error != 1)
            {
                printf("Incorrect input");

                for(int k = 0; k < row; k++)
                {
                    if(*(array + k) != NULL)
                    {
                        free(*(array + k));
                    }
                }
                free(array);

                return 1;
            }
        }
    }

    int choice;
    printf("Enter choice: ");
    error = scanf("%i",&choice);
    if(error != 1)
    {
        printf("Incorrect input");

        for(int i = 0; i < row; i++)
        {
            if(*(array + i) != NULL)
            {
                free(*(array + i));
            }
        }
        free(array);

        return 1;
    }
    if(choice < 0 || choice > 2)
    {
        printf("Incorrect input data");

        for(int i = 0; i < row; i++)
        {
            if(*(array + i) != NULL)
            {
                free(*(array + i));
            }
        }
        free(array);

        return 2;
    }

    sort_rows(array, column, row, *(funcs + choice));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf("%d ",*(*(array + i) + j));
        }
        printf("\n");
    }

    for(int i = 0; i < row; i++)
    {
        if(*(array + i) != NULL)
        {
            free(*(array + i));
        }
    }

    free(array);
    return 0;
}
