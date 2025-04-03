#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_utils.h"

int main()
{
    char *file_in = calloc(20, sizeof(char));
    if (file_in == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("\nEnter:");
    scanf("%19[^\n]s", file_in);

    int deadinside;
    struct matrix_t *mat_in;
    int size_of_in = (int) strlen(file_in);

    if (*(file_in + size_of_in - 4) != '.' || *(file_in + size_of_in - 3) != 't' || *(file_in + size_of_in - 2) != 'x' || *(file_in + size_of_in - 1) != 't')
    {
        if (*(file_in + size_of_in - 4) == '.' && *(file_in + size_of_in - 3) == 'b' && *(file_in + size_of_in - 2) == 'i' && *(file_in + size_of_in - 1) == 'n')
        {
            mat_in = matrix_load_b(file_in, &deadinside);

            switch (deadinside)
            {
                case 2:
                    printf("Couldn't open file");

                    free(file_in);

                    return 4;
                case 3:
                    printf("File corrupted");

                    free(file_in);

                    return 6;
                case 4:
                    printf("Failed to allocate memory");

                    free(file_in);

                    return 8;
                default:
                    free(file_in);
                    break;
            }
        }
        else
        {
            free(file_in);

            printf("Unsupported file format");

            return 7;
        }
    }
    else
    {
        mat_in = matrix_load_t(file_in, &deadinside);
        switch (deadinside)
        {
            case 2:
                printf("Couldn't open file");

                free(file_in);

                return 4;
            case 3:
                printf("File corrupted");

                free(file_in);

                return 6;
            case 4:
                printf("Failed to allocate memory");

                free(file_in);

                return 8;
            default:
                free(file_in);
                break;
        }
    }

    char *file_out = calloc(20, sizeof(char));
    if (file_out == NULL)
    {
        printf("Failed to allocate memory");

        matrix_destroy_struct(&mat_in);

        return 8;
    }

    printf("Enter file_out: ");

    while (getchar() != '\n');
    scanf("%19[^\n]s", file_out);

    int hot_moms;
    struct matrix_t *mat_out;
    int size_of_out = (int) strlen(file_out);

    if (*(file_out + size_of_out - 4) != '.' || *(file_out + size_of_out - 3) != 't' || *(file_out + size_of_out - 2) != 'x' || *(file_out + size_of_out - 1) != 't')
    {
        if (*(file_out + size_of_out - 4) == '.' && *(file_out + size_of_out - 3) == 'b' && *(file_out + size_of_out - 2) == 'i' && *(file_out + size_of_out - 1) == 'n')
        {
            mat_out = matrix_load_b(file_out, &hot_moms);
            switch (hot_moms)
            {
                case 2:
                    printf("Couldn't open file");
                    matrix_destroy_struct(&mat_in);
                    free(file_out);
                    return 4;
                case 3:
                    printf("File corrupted");
                    matrix_destroy_struct(&mat_in);
                    free(file_out);
                    return 6;
                case 4:
                    printf("Failed to allocate memory");

                    matrix_destroy_struct(&mat_in);
                    free(file_out);

                    return 8;
                default:
                    free(file_out);
                    break;
            }
        }
        else
        {
            printf("Unsupported file format");

            free(file_out);
            matrix_destroy_struct(&mat_in);

            return 7;
        }
    }
    else
    {
        mat_out = matrix_load_t(file_out, &hot_moms);
        switch (hot_moms)
        {
            case 2:
                printf("Couldn't open file");
                matrix_destroy_struct(&mat_in);
                free(file_out);
                return 4;
            case 3:
                printf("File corrupted");
                matrix_destroy_struct(&mat_in);
                free(file_out);
                return 6;
            case 4:
                printf("Failed to allocate memory");
                matrix_destroy_struct(&mat_in);
                free(file_out);
                return 8;
            default:
                free(file_out);
                break;
        }
    }

    struct matrix_t *add = matrix_add(mat_in, mat_out);
    if (add && add->ptr)
    {
        matrix_display(add);
    }
    else
    {
        printf("Error\n");
    }

    struct matrix_t *sub = matrix_subtract(mat_in, mat_out);
    if (sub && sub->ptr)
    {
        matrix_display(sub);
    }
    else
    {
        printf("Error\n");
    }

    struct matrix_t *mul = matrix_multiply(mat_in, mat_out);
    if (mul && mul->ptr)
    {
        matrix_display(mul);
    }
    else
    {
        printf("Error");
    }

    matrix_destroy_struct(&mat_in);
    matrix_destroy_struct(&mat_out);
    matrix_destroy_struct(&add);
    matrix_destroy_struct(&sub);
    matrix_destroy_struct(&mul);

    return 0;
}
