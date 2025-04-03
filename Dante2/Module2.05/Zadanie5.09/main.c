#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image_utils.h"

int main()
{
    int error;

    char *filename = malloc(40 * sizeof(char));
    if (filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter file name: ");
    scanf("%39s", filename);

    int err_code;
    struct image_t *img = load_image_t(filename, &err_code);
    if (err_code == 2)
    {
        printf("Couldn't open file");

        free(filename);

        return 4;
    }
    else if (err_code == 1 || err_code == 3)
    {
        printf("File corrupted");

        destroy_image(&img);
        free(filename);

        return 6;
    }
    else if (err_code == 4)
    {
        printf("Failed to allocate memory");

        destroy_image(&img);
        free(filename);

        return 8;
    }

    struct image_t *vertical_hueta = image_flip_vertical(img);
    if (vertical_hueta == NULL)
    {
        printf("Failed to allocate memory");

        destroy_image(&img);
        free(filename);

        return 8;
    }

    char *new_filename = malloc(50 * sizeof(char));
    if (new_filename == NULL)
    {
        printf("Failed to allocate memory");

        destroy_image(&vertical_hueta);
        destroy_image(&img);
        free(filename);

        return 8;
    }
    strcpy(new_filename, "mirror_v_");
    strcat(new_filename, filename);

    error = save_image_t(new_filename, vertical_hueta);
    if (error != 0)
    {
        printf("Couldn't create file");
    }
    else
    {
        printf("File saved");
    }
    printf("\n");

    struct image_t *horizontal_hueta = image_flip_horizontal(img);
    if (horizontal_hueta == NULL)
    {
        printf("Failed to allocate memory");

        destroy_image(&vertical_hueta);
        destroy_image(&img);
        free(filename);
        free(new_filename);

        return 8;
    }
    strcpy(new_filename, "mirror_h_");
    strcat(new_filename, filename);

    error = save_image_t(new_filename, horizontal_hueta);
    if (error != 0)
    {
        printf("Couldn't create file");
    }
    else
    {
        printf("File saved");
    }
    printf("\n");

    struct image_t *negative_hueta = image_negate(img);
    if (negative_hueta == NULL)
    {
        printf("Failed to allocate memory");

        destroy_image(&horizontal_hueta);
        destroy_image(&vertical_hueta);
        destroy_image(&img);
        free(filename);
        free(new_filename);

        return 8;
    }
    strcpy(new_filename, "invert_");
    strcat(new_filename, filename);

    error = save_image_t(new_filename, negative_hueta);
    if (error != 0)
    {
        printf("Couldn't create file");
    }
    else
    {
        printf("File saved");
    }
    printf("\n");

    destroy_image(&horizontal_hueta);
    destroy_image(&vertical_hueta);
    destroy_image(&negative_hueta);
    destroy_image(&img);
    free(filename);
    free(new_filename);
    return 0;
}
