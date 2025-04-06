#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include "dictionary.h"

int main()
{
    char *filename = malloc(50 * sizeof(char));
    if (filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    scanf("%49s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Couldn't open file");
        free(filename);
        return 4;
    }

    int error;
    struct dictionary_t *working_on_that = create_dictionary(10, &error);
    if (error != 0)
    {
        printf("Failed to allocate memory");
        free(filename);
        fclose(file);
        return 8;
    }

    char *word = malloc(21 * sizeof(char));
    if (word == NULL)
    {
        printf("Failed to allocate memory\n");
        destroy_dictionary(&working_on_that);
        free(filename);
        fclose(file);
        return 8;
    }

    int size = 0;
    while (!feof(file))
    {
        int temp_shit = fgetc(file);

        if (!isalpha(temp_shit))
        {
            
        }
        else
        {
            *(word + size) = (char) temp_shit;
            size++;
        }
        if (isalpha(temp_shit) || size <= 0)
        {
            continue;
        }
        *(word + size) = '\0';
        size = 0;

        error = dictionary_add_word(working_on_that, word);
        if (error == 0)
        {
            continue;
        }

        printf("Failed to allocate memory\n");
        destroy_dictionary(&working_on_that);
        free(filename);
        fclose(file);
        free(word);
        return 8;
    }

    dictionary_display(working_on_that);

    if (working_on_that->size == 0)
    {
        printf("Nothing to show\n");
    }

    destroy_dictionary(&working_on_that);
    free(filename);
    fclose(file);
    free(word);
    return 0;
}
