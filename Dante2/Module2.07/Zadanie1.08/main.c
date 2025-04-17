#include <stdio.h>
#include <malloc.h>
#include "comparators.h"

int main()
{
    int error;

    int your_pick;
    printf("Enter your pick: ");
    error = scanf("%i",&your_pick);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(your_pick > 2 || your_pick < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int size;
    printf("Enter size: ");
    error = scanf("%i",&size);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Incorrect input data");
        return 2;
    }

    int *integer_array;
    double *double_array;
    struct point_t *struct_array;

    func temporary[] = {comp_int, comp_double, comp_point};

    switch (your_pick)
    {
        case 0: // int
            integer_array = malloc(sizeof(int) * size);
            if(integer_array == NULL)
            {
                printf("Failed to allocate memory");
                return 8;
            }

            printf("Enter integer array: ");
            for(int i = 0; i < size; i++)
            {
                error = scanf("%i", &*(integer_array + i));
                if(error != 1)
                {
                    printf("Incorrect input");
                    free(integer_array);
                    return 1;
                }
            }

            sort(integer_array, size, sizeof(int), *(temporary + your_pick));

            for(int i = 0; i < size; i++)
            {
                printf("%i ", *(integer_array + i));
            }
            free(integer_array);
            return 0;
        case 1: // double
            double_array = malloc(sizeof(double) * size);
            if(double_array == NULL)
            {
                printf("Failed to allocate memory");
                return 8;
            }

            printf("Enter double array: ");
            for(int i = 0; i < size; i++)
            {
                error = scanf("%lf", &*(double_array + i));
                if(error != 1)
                {
                    printf("Incorrect input");
                    free(double_array);
                    return 1;
                }
            }

            sort(double_array, size, sizeof(double), *(temporary + your_pick));

            for(int i = 0; i < size; i++)
            {
                printf("%lf ", *(double_array + i));
            }
            free(double_array);
            return 0;
        default: // struct
            struct_array = malloc(sizeof(struct point_t) * size);
            if(struct_array == NULL)
            {
                printf("Failed to allocate memory");
                return 8;
            }

            printf("Enter struct array: ");
            for(int i = 0; i < size; i++)
            {
                error = scanf("%lf %lf", &((struct_array + i)->x), &((struct_array + i)->y));
                if(error != 2)
                {
                    printf("Incorrect input");
                    free(struct_array);
                    return 1;
                }
            }

            sort(struct_array, size, sizeof(struct point_t), *(temporary + your_pick));

            for(int i = 0; i < size; i++)
            {
                printf("%lf %lf\n",(struct_array + i)->x, (struct_array + i)->y);
            }
            free(struct_array);
            return 0;
    }
}
