#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "image_utils.h"

int main()
{
    int error = 0;

    char* filename = calloc(40, sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter file filename: ");
    scanf("%39s", filename);

    struct image_t* im1;
    im1 = load_image_t(filename, &error);
    if(error == 2)
    {
        printf("Couldn't open file");
        free(filename);
        return 4;
    }
    else if(error == 4)
    {
        printf("Failed to allocate memory");
        free(filename);
        return 8;
    }
    else if(error == 3)
    {
        printf("File corrupted");
        free(filename);
        return 6;
    }

    while(getchar() != '\n');

    printf("Input number: ");

    int number;
    error = scanf("%i", &number);
    if(error != 1)
    {
        printf("Incorrect input");
        destroy_image(&im1);
        free(filename);
        return 1;
    }
    if(number < 1)
    {
        printf("Incorrect input data");
        destroy_image(&im1);
        free(filename);
        return 2;
    }

    char *new_file = malloc(40 * sizeof(char));
    if(new_file == NULL)
    {
        printf("Failed to allocate memory");
        destroy_image(&im1);
        free(filename);
        return 8;
    }

    struct image_t* im2 = NULL;
    for(int i = 0; i < number; ++i)
    {
        printf("Enter a filename: ");
        scanf("%39s", new_file);

        int letter;
        while ((letter = getchar()) != '\n' && letter != EOF);

        if(im2 != NULL)
        {
            destroy_image(&im2);
        }

        im2 = load_image_t(new_file, &error);
        if(error == 2)
        {
            printf("Couldn't open file\n");
            continue;
        }
        else if(error == 4)
        {
            printf("Failed to allocate memory");
            destroy_image(&im1);
            free(filename);
            free(new_file);
            return 8;
        }
        else if(error == 3)
        {
            printf("File corrupted\n");
            continue;
        }

        printf("Enter coordinates: ");

        int x;

        error = scanf("%i ", &x);
        if(error != 1)
        {
            printf("Incorrect input");
            destroy_image(&im2);
            destroy_image(&im1);
            free(filename);
            free(new_file);
            return 1;
        }

        int y;

        error = scanf("%i", &y);
        if(error != 1)
        {
            printf("Incorrect input");
            destroy_image(&im2);
            destroy_image(&im1);
            free(filename);
            free(new_file);
            return 1;
        }

        if(x < 0 || y < 0)
        {
            printf("Incorrect input data\n");
            continue;
        }
        if(x >= im1->width || y >= im1->height)
        {
            printf("Incorrect input data\n");
            continue;
        }
        if(im2->width > im1->width || im2->height > im1->height)
        {
            printf("Incorrect input data\n");
            continue;
        }
        if(x + im2->width > im1->width || y + im2->height > im1->height)
        {
            printf("Incorrect input data\n");
            continue;
        }
        draw_image(im1, im2, x, y);
    }
    destroy_image(&im2);
    free(new_file);

    int counter = 0;
    char *temp_storage_to_eee_idk = malloc(100 * sizeof(char));
    for(int i = (int)strlen(filename) - 1; i > 0; --i)
    {
        if(*(filename + i) == '.')
        {
            counter = i;
            break;
        }
    }

    strncpy(temp_storage_to_eee_idk, filename, counter);
    *(temp_storage_to_eee_idk + counter) = '\0';
    const char* extension = "_modified";
    strcat(temp_storage_to_eee_idk, extension);
    strcat(temp_storage_to_eee_idk, filename + counter);

    error = save_image_t(temp_storage_to_eee_idk, im1);
    if(error == 2 || error == 3)
    {
        printf("Couldn't create file\n");
        destroy_image(&im1);
        free(filename);
        free(temp_storage_to_eee_idk);
        return 5;
    }

    printf("File saved");
    destroy_image(&im1);
    free(filename);
    free(temp_storage_to_eee_idk);
    return 0;
}
