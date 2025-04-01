#include <stdio.h>
#include "array.h"

int main()
{
    int size, error;

    printf("Enter: ");
    error = scanf("%i", &size);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct array_t *first;
    error = array_create_struct_float(&first, size);
    if(error != 0)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    float number;
    printf("Enter: ");
    for(int i = 0; i < size; i++)
    {
        error = scanf("%f",&number);
        if(error != 1)
        {
            printf("Incorrect input");

            array_destroy_struct_float(&first);

            return 1;
        }
        array_push_back_float(first, number);
    }


    printf("Enter: ");
    error = scanf("%i", &size);
    if(error != 1)
    {
        printf("Incorrect input");

        array_destroy_struct_float(&first);

        return 1;
    }
    if(size <= 0)
    {
        printf("Incorrect input data");

        array_destroy_struct_float(&first);

        return 2;
    }

    struct array_t *second;
    error = array_create_struct_float(&second, size);
    if(error != 0)
    {
        printf("Failed to allocate memory");

        array_destroy_struct_float(&first);

        return 8;
    }

    printf("Enter: ");
    for(int i = 0; i < size; i++)
    {
        error = scanf("%f",&number);
        if(error != 1)
        {
            printf("Incorrect input");

            array_destroy_struct_float(&first);
            array_destroy_struct_float(&second);

            return 1;
        }
        array_push_back_float(second, number);
    }


    struct array_t *third;
    error = add_vectors(first, second, &third);
    if(error == 1)
    {
        printf("Operation not permitted\n");
    }
    else if(error == 2)
    {
        printf("Failed to allocate memory");

        array_destroy_struct_float(&first);
        array_destroy_struct_float(&second);

        return 8;
    }
    else
    {
        array_display_float(third);
    }

    struct array_t *fourth;
    error = subtract_vectors(first, second, &fourth);
    if(error == 1)
    {
        printf("Operation not permitted\n");
    }
    else if(error == 2)
    {
        printf("Failed to allocate memory");

        array_destroy_struct_float(&first);
        array_destroy_struct_float(&second);
        array_destroy_struct_float(&third);

        return 8;
    }
    else
    {
        array_display_float(fourth);
    }

    float errorchik;

    errorchik = dot_product(first, second);
    if(errorchik == -1)
    {
        printf("Operation not permitted\n");
    }
    else
    {
        printf("%.2f\n", errorchik);
    }

    errorchik = angle_between_vectors(first, second);
    if(errorchik == -1)
    {
        printf("Operation not permitted\n");
    }
    else
    {
        printf("%.2f\n", errorchik);
    }

    errorchik = length(first);
    if(errorchik == -1)
    {
        printf("Operation not permitted\n");
    }
    else
    {
        printf("%.2f\n", errorchik);
    }

    errorchik = length(second);
    if(errorchik == -1)
    {
        printf("Operation not permitted\n");
    }
    else
    {
        printf("%.2f\n", errorchik);
    }

    struct array_t *fifth;
    error = normalize_vector(first, &fifth);
    if(error == 2)
    {
        printf("Failed to allocate memory");

        array_destroy_struct_float(&first);
        array_destroy_struct_float(&second);
        array_destroy_struct_float(&third);
        array_destroy_struct_float(&fourth);

        return 8;
    }
    if(error == 1 || error == 3)
    {
        printf("Operation not permitted\n");
    }
    else
    {
        array_display_float(fifth);
    }

    struct array_t *sixth;
    error = normalize_vector(second, &sixth);
    if(error == 2)
    {
        printf("Failed to allocate memory");

        array_destroy_struct_float(&first);
        array_destroy_struct_float(&second);
        array_destroy_struct_float(&third);
        array_destroy_struct_float(&fourth);
        array_destroy_struct_float(&fifth);

        return 8;
    }
    if(error == 1 || error == 3)
    {
        printf("Operation not permitted\n");
    }
    else
    {
        array_display_float(sixth);
    }

    array_destroy_struct_float(&first);
    array_destroy_struct_float(&second);
    array_destroy_struct_float(&third);
    array_destroy_struct_float(&fourth);
    array_destroy_struct_float(&fifth);
    array_destroy_struct_float(&sixth);

    return 0;
}
