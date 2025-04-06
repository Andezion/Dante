#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

int helper_for_myself(struct dictionary_t *dict, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return 1;
    }

    char *helper = malloc(sizeof(char) * 1000);
    if(helper == NULL)
    {
        fclose(file);
        return 2;
    }

    while (fscanf(file, "%999s", helper) == 1)
    {
        char *this_is_not_dupa = helper;
        for (char *this_should_work = helper; *this_should_work; this_should_work++)
        {
            if (isalpha((unsigned char)*this_should_work))
            {
                *this_is_not_dupa++ = *this_should_work;
            }
        }
        *this_is_not_dupa = '\0';

        if (*helper != '\0')
        {
            if (dictionary_add_word(dict, helper) != 0)
            {
                free(helper);
                fclose(file);

                return 3;
            }
        }
    }

    free(helper);
    fclose(file);
    return 0;
}

int main()
{
    int error;

    char *filename = malloc(sizeof(char) * 40);
    if(filename == NULL)
    {
        printf("Failed to allocate memory\n");
        return 8;
    }

    printf("Enter: ");
    scanf("%39[^\n]", filename);
    while(getchar() != '\n');

    int type;
    printf("Enter type: ");
    error = scanf("%i",&type);
    if(error != 1)
    {
        printf("Incorrect input\n");
        free(filename);
        return 1;
    }
    if(type != 0 && type != 1)
    {
        printf("Incorrect input data\n");
        free(filename);
        return 2;
    }

    struct dictionary_t *dict;
    if(type == 1)
    {
        int err_code;
        dict = create_dictionary(1, &err_code);
        if(err_code == 2)
        {
            printf("Failed to allocate memory\n");

            free(filename);

            return 8;
        }

        error = helper_for_myself(dict, filename);
        if(error == 2)
        {
            printf("Failed to allocate memory\n");

            destroy_dictionary(&dict);
            free(filename);

            return 8;
        }
        if(error == 3)
        {
            printf("File corrupted\n");

            destroy_dictionary(&dict);
            free(filename);

            return 6;
        }
        if(error == 1)
        {
            printf("Couldn't open file\n");

            destroy_dictionary(&dict);
            free(filename);

            return 4;
        }
    }
    if(type == 0)
    {
        int err_code;

        dict = load_dictionary_b(filename, &err_code);
        if(err_code == 4)
        {
            printf("Failed to allocate memory\n");

            free(filename);

            return 8;
        }
        if(err_code == 3)
        {
            printf("File corrupted\n");

            destroy_dictionary(&dict);
            free(filename);

            return  6;
        }
        if(err_code == 2)
        {
            printf("Couldn't open file\n");

            free(filename);

            return 4;
        }
    }

    char *new_filename = malloc(sizeof(char) * (strlen(filename) + 1));
    if(new_filename == NULL)
    {
        printf("Failed to allocate memory\n");

        destroy_dictionary(&dict);
        free(filename);

        return 8;
    }
    strcpy(new_filename, filename);

    error = dictionary_sort_alphabetically(dict);
    if(error == 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (type == 0)
    {
        size_t size = strlen(filename);
        if (size >= 4 && strcmp(filename + size - 4, ".bin") == 0)
        {
            strcpy(filename + size - 4, "_alpha.bin");
        }
    }
    if (type == 1)
    {
        size_t len = strlen(filename);
        if (len >= 4 && strcmp(filename + len - 4, ".txt") == 0)
        {
            strcpy(filename + len - 4, "_alpha.txt");
        }
    }

    error = save_dictionary_b(dict, filename);
    if(error == 0)
    {
        printf("File saved\n");
    }
    else
    {
        printf("Couldn't create file\n");
    }

    error = dictionary_sort_occurence(dict);
    if(error == 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    strcpy(filename, new_filename);
    if (type == 0)
    {
        size_t size = strlen(filename);
        if (size >= 4 && strcmp(filename + size - 4, ".bin") == 0)
        {
            strcpy(filename + size - 4, "_occ.bin");
        }
    }
    if (type == 1)
    {
        size_t len = strlen(filename);
        if (len >= 4 && strcmp(filename + len - 4, ".txt") == 0)
        {
            strcpy(filename + len - 4, "_occ.txt");
        }
    }

    error = save_dictionary_b(dict, filename);
    if(error == 0)
    {
        printf("File saved\n");
    }
    else
    {
        printf("Couldn't create file\n");
    }

    destroy_dictionary(&dict);
    free(new_filename);
    free(filename);
    return 0;
}






















