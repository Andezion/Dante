#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "array.h"

int main()
{
    char *filename = malloc(sizeof(char) * 50);
    char *new_filename = malloc(sizeof(char) * 50);

    if(!filename)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    if(!new_filename)
    {
        printf("Failed to allocate memory");
        free(filename);
        return 8;
    }

    printf("Enter: ");
    scanf("%49s", filename);
    while(getchar() != '\n');
    FILE *file = fopen(filename, "rt");
    if(!file)
    {
        printf("Couldn't open file");

        free(new_filename);
        free(filename);

        return 4;
    }
    printf("Enter: ");
    scanf("%49s",new_filename);
    while(getchar() != '\n');
    FILE *file1 = fopen(new_filename, "rt");
    if(!file1)
    {
        printf("Couldn't open file");

        free(new_filename);
        free(filename);
        fclose(file);

        return 4;
    }

    char *buffer = malloc(sizeof(char) * 41);
    if(!buffer)
    {
        printf("Failed to allocate memory");

        free(new_filename);
        free(filename);
        fclose(file);
        fclose(file1);

        return 8;
    }

    int err_code;
    struct dictionary_t *dict_one = create_dictionary(10, &err_code);
    if(dict_one == NULL)
    {
        printf("Failed to allocate memory");

        free(new_filename);
        free(filename);
        free(buffer);
        fclose(file);
        fclose(file1);

        return 8;
    }

    int temp;
    while(!feof(file))
    {
        temp = fscanf(file, "%s", buffer);
        if(!temp)
        {
            break;
        }

        strtok(buffer, "."); strtok(buffer, ","); strtok(buffer, "?"); strtok(buffer, "!");

        temp = dictionary_add_word(dict_one, buffer);
        if(temp == 2)
        {
            printf("Failed to allocate memory");

            destroy_dictionary(&dict_one);
            free(new_filename);
            free(filename);
            free(buffer);
            fclose(file);
            fclose(file1);

            return 8;
        }
    }

    struct dictionary_t *dict_two = create_dictionary(10, &err_code);
    if(dict_two == NULL)
    {
        printf("Failed to allocate memory");

        destroy_dictionary(&dict_one);
        free(new_filename);
        free(filename);
        fclose(file1);
        fclose(file);
        free(buffer);

        return 8;
    }

    while (!feof(file1))
    {
        temp = fscanf(file1, "%s", buffer);
        if(!temp)
        {
            break;
        }

        strtok(buffer, "."); strtok(buffer, ","); strtok(buffer, "?"); strtok(buffer, "!");

        temp = dictionary_add_word(dict_two, buffer);
        if(temp == 2)
        {
            printf("Failed to allocate memory");

            destroy_dictionary(&dict_one);
            destroy_dictionary(&dict_two);
            free(new_filename);
            free(filename);
            fclose(file1);
            fclose(file);
            free(buffer);

            return 8;
        }
    }

    struct dictionary_t *test_one = create_dictionary(10, &err_code);
    if(!test_one)
    {
        printf("Failed to allocate memory");

        destroy_dictionary(&dict_one);
        destroy_dictionary(&dict_two);
        free(new_filename);
        free(filename);
        free(buffer);

        return 8;
    }

    for(int i = 0; i < dict_one->size; i++)
    {
        for(int j = 0; j < (dict_one->wc + i)->counter; j++)
        {
            err_code = dictionary_add_word(test_one, (dict_one->wc + i)->word);
            if(err_code == 2)
            {
                printf("Failed to allocate memory");

                destroy_dictionary(&test_one);
                destroy_dictionary(&dict_one);
                destroy_dictionary(&dict_two);
                free(new_filename);
                free(filename);
                fclose(file1);
                fclose(file);
                free(buffer);

                return 8;
            }
        }
    }
    for(int i = 0; i < dict_two->size; i++)
    {
        for(int j = 0; j < (dict_two->wc + i)->counter; j++)
        {
            err_code = dictionary_add_word(test_one, (dict_two->wc + i)->word);
            if(err_code == 2)
            {
                printf("Failed to allocate memory");

                destroy_dictionary(&test_one);
                destroy_dictionary(&dict_one);
                destroy_dictionary(&dict_two);
                free(new_filename);
                free(filename);
                fclose(file1);
                fclose(file);
                free(buffer);

                return 8;
            }
        }
    }

    struct array_t *type_one;
    err_code = array_create_struct_float(&type_one, test_one->size);
    if(err_code == 1)
    {
        printf("Failed to allocate memory");

        destroy_dictionary(&test_one);
        destroy_dictionary(&dict_one);
        destroy_dictionary(&dict_two);
        free(new_filename);
        free(filename);
        fclose(file1);
        fclose(file);
        free(buffer);

        return 8;
    }

    struct array_t *type_two;
    err_code = array_create_struct_float(&type_two, test_one->size);
    if(err_code == 1)
    {
        printf("Failed to allocate memory");

        array_destroy_struct_float(&type_one);
        destroy_dictionary(&test_one);
        destroy_dictionary(&dict_one);
        destroy_dictionary(&dict_two);
        free(new_filename);
        free(filename);
        fclose(file1);
        fclose(file);
        free(buffer);

        return 8;
    }

    int sum_type1 = 0, sum_type2 = 0;

    for(int i = 0; i < dict_one->size; i++)
    {
        sum_type1 = sum_type1 + (dict_one->wc + i)->counter;
    }
    for(int i = 0; i < dict_two->size; i++)
    {
        sum_type2 = sum_type2 + (dict_two->wc + i)->counter;
    }

    float helper;
    struct word_count_t *word;
    for(int i = 0; i < test_one->size; i++)
    {
        word = dictionary_find_word(dict_one, (test_one->wc + i)->word);
        if(word == NULL)
        {
            array_push_back_float(type_one, 0);
        }
        else
        {
            helper = (float)word->counter;
            helper = helper / (float)(sum_type1 / 1.0);
            array_push_back_float(type_one, helper);
        }

        word = dictionary_find_word(dict_two, (test_one->wc + i)->word);
        if(word == NULL)
        {
            array_push_back_float(type_two, 0);
        }
        else
        {
            helper = (float)word->counter;
            helper = helper / (float)(sum_type2 / 1.0);
            array_push_back_float(type_two, helper);
        }
    }

    double val1 = dot_product(type_one, type_two);
    double val2 = length(type_one) * length(type_two);

    printf("Result is: %.5f\n", val1 / val2);

    array_destroy_struct_float(&type_one);
    array_destroy_struct_float(&type_two);
    destroy_dictionary(&test_one);
    destroy_dictionary(&dict_one);
    destroy_dictionary(&dict_two);
    free(new_filename);
    free(filename);
    fclose(file1);
    fclose(file);
    free(buffer);

    return 0;
}
