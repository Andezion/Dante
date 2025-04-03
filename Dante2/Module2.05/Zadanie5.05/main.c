#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    int error;

    int width, height;
    printf("Enter: ");

    error = scanf("%i %i",&width, &height);
    if(error != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(width <= 0 || height <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    struct matrix_t m;
    error = matrix_create(&m, width, height);
    if(error == 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(error == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter:\n");
    error = matrix_read(&m);
    if(error == 2)
    {
        printf("Incorrect input");
        matrix_destroy(&m);
        return 1;
    }

    char *name = malloc(sizeof(char) * 40);
    if(name == NULL)
    {
        printf("Failed to allocate memory");
        matrix_destroy(&m);
        return 8;
    }

    while(getchar() != '\n');

    printf("Enter name: ");
    scanf("%39[^\n]",name);

    while(getchar() != '\n');

    char *helper = strrchr(name, '.');
    if(!helper)
    {
        matrix_destroy(&m);
        free(name);

        printf("Unsupported file format");
        return 7;
    }

    int type_bin = strcmp(helper, ".bin");
    int type_txt = strcmp(helper, ".txt");
    if(strcmp(helper, ".bin") != 0 && strcmp(helper, ".txt") != 0)
    {
        matrix_destroy(&m);
        free(name);

        printf("Unsupported file format");
        return 7;
    }

    struct matrix_t *tm = matrix_transpose(&m);
    if(!tm)
    {
        matrix_destroy(&m);
        free(name);

        printf("Failed to allocate memory");
        return 8;
    }

    if(type_txt == 0)
    {
        error = matrix_save_t(tm, name);
    }
    if(type_bin == 0)
    {
        error = matrix_save_b(tm, name);
    }
    matrix_destroy(&m);
    matrix_destroy_struct(&tm);
    free(name);

    if(error == 2)
    {
        printf("Couldn't create file");
        return 5;
    }
    if(error == 3)
    {
        printf("File save error");
        return 6;
    }

    printf("File saved");
    return 0;
}
