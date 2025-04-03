#include <stdio.h>
#include <stdlib.h>
#include "image_utils.h"

int main()
{
    int error;

    char *filename = malloc(40 * sizeof(char));
    if (!filename)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter name: ");
    scanf("%39[^\n]", filename);
    while(getchar()!='\n');

    int err_code;
    struct image_t *test_shit = load_image_t(filename, &err_code);
    if (test_shit == NULL)
    {
        if (err_code == 2)
        {
            printf("Couldn't open file");
            free(filename);
            return 4;
        }
        if (err_code == 3)
        {
            printf("File corrupted");
            free(filename);
            return 6;
        }
        if(err_code == 4)
        {
            printf("Failed to allocate memory");
            free(filename);
            return 8;
        }

    }

    printf("Enter some shit: ");
    struct rectangle_t temp_struct;
    error = scanf("%i %i %i %i", &temp_struct.p.x, &temp_struct.p.y, &temp_struct.width, &temp_struct.height);
    if (error != 4)
    {
        printf("Incorrect input");
        destroy_image(&test_shit);
        free(filename);
        return 1;
    }

    int type;
    printf("Enter what to do: ");
    error = scanf("%i", &type);
    if (error != 1)
    {
        printf("Incorrect input");
        destroy_image(&test_shit);
        free(filename);
        return 1;
    }
    error = image_draw_rectangle(test_shit, &temp_struct, type);
    if (error == 1)
    {
        printf("Incorrect input data");
        destroy_image(&test_shit);
        free(filename);
        return 2;
    }
    error = save_image_t(filename, test_shit);
    if (error != 0)
    {
        printf("Couldn't create file");
        destroy_image(&test_shit);
        free(filename);
        return 5;
    }

    printf("File saved");
    destroy_image(&test_shit);
    free(filename);
    return 0;
}
