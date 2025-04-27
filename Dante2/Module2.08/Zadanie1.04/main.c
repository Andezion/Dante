#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *concatenate(int count, ...);

int main()
{
    int error;

    char **array = malloc(sizeof(char *) * 4);
    if(array == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i = 0; i < 4; i++)
    {
        *(array + i) = malloc(sizeof(char) * 1001);
        if(*(array + i) == NULL)
        {
            printf("Failed to allocate memory");

            for(int j = 0; j < i; j++)
            {
                free(*(array + j));
            }
            free(array);

            return 8;
        }
    }

    int counter;
    printf("Enter counter: ");
    error = scanf("%i",&counter);
    if(error != 1)
    {
        printf("Incorrect input");

        for(int i = 0; i < 4; i++)
        {
            free(*(array + i));
        }
        free(array);

        return 1;
    }
    if(counter > 4 || counter < 2)
    {
        printf("Incorrect input data");

        for(int i = 0; i < 4; i++)
        {
            free(*(array + i));
        }
        free(array);

        return 2;
    }

    getchar();

    printf("Now enter data:\n");
    for(int i = 0; i < counter; i++)
    {
        scanf("%1000[^\n]",*(array + i));
        while(getchar() != '\n');
    }

    char *temp = NULL;

    if(counter == 2)
    {
        temp = concatenate(2, *(array + 0), *(array + 1));
    }
    else if(counter == 3)
    {
        temp = concatenate(3, *(array + 0), *(array + 1), *(array + 2));
    }
    else if(counter == 4)
    {
        temp = concatenate(4, *(array + 0), *(array + 1), *(array + 2), *(array + 3));
    }
    else
    {
        printf("Something wrong dude...");
    }

    if(temp == NULL)
    {
        printf("Failed to allocate memory");

        for(int i = 0; i < 4; i++)
        {
            free(*(array + i));
        }
        free(array);

        return 8;
    }

    printf("%s", temp);

    for(int i = 0; i < 4; i++)
    {
        free(*(array + i));
    }
    free(temp);
    free(array);

    return 0;
}

char *concatenate(int count, ...)
{
    if (count >= 1)
    {
        va_list begin;
        va_start(begin, count);

        char *main_storage = va_arg(begin, char *);
        int size_of_main_storage = (int) strlen(main_storage) + 1;
        char *resulted = malloc(size_of_main_storage * sizeof(char));
        if (resulted != NULL)
        {

            strcpy(resulted, main_storage);

            int how_long_is_our_string = size_of_main_storage;
            for (int i = 0; i < count - 1; i++)
            {
                char *temporary_storage = va_arg(begin, char *);

                int curr_len = (int) strlen(temporary_storage) + 1;
                how_long_is_our_string = how_long_is_our_string + curr_len;

                char *result = realloc(resulted, sizeof(char) * how_long_is_our_string);
                if (result != NULL)
                {
                    resulted = result;

                    strcat(resulted, " ");
                    strcat(resulted, temporary_storage);
                }
                else
                {
                    free(resulted);
                    return va_end(begin), NULL;
                }
            }
            va_end(begin);
            return resulted;
        }
        va_end(begin);
        return NULL;
    }
    return NULL;
}
