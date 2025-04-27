#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int concatenate(char *source, int size, int counter, ...);

int main()
{
    int error;

    char **array = malloc(4 * sizeof(char *));
    if (array == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for (int i = 0; i < 4; i++)
    {
        *(array + i) = malloc(1001 * sizeof(char));
        if (*(array + i) == NULL)
        {
            printf("Failed to allocate memory");

            for (int j = 0; j < i; j++)
            {
                free(*(array + j));
            }
            free(array);

            return 8;
        }
    }

    char *temporary_shit_we_are_using = malloc(sizeof(char) * 4004);
    if (temporary_shit_we_are_using == NULL)
    {
        printf("Failed to allocate memory");

        for (int i = 0; i < 4; i++)
        {
            free(*(array + i));
        }
        free(array);

        return 8;
    }

    int number;
    printf("Enter how much: ");
    error = scanf("%i", &number);
    if (error != 1)
    {
        printf("Incorrect input");

        for (int i = 0; i < 4; i++)
        {
            free(*(array + i));
        }
        free(temporary_shit_we_are_using);
        free(array);

        return 1;
    }
    if (number > 4 || number < 2)
    {
        printf("Incorrect input data");

        for (int i = 0; i < 4; i++)
        {
            free(*(array + i));
        }
        free(temporary_shit_we_are_using);
        free(array);

        return 2;
    }

    getchar();

    printf("Enter your data: ");
    for (int i = 0; i < number; i++)
    {
        scanf("%1000[^\n]", *(array + i));
        while (getchar() != '\n');
    }

    if(number == 2)
    {
        concatenate(temporary_shit_we_are_using, 4004, 2, *array, *(array + 1));
    }
    else if(number == 3)
    {
        concatenate(temporary_shit_we_are_using, 4004, 3, *array, *(array + 1), *(array + 2));
    }
    else if(number == 4)
    {
        concatenate(temporary_shit_we_are_using, 4004, 4, *array, *(array + 1), *(array + 2), *(array + 3));
    }
    else
    {
        printf("Something is wrong...");
    }

    printf("%s", temporary_shit_we_are_using);

    for (int i = 0; i < 4; i++)
    {
        free(*(array + i));
    }
    free(temporary_shit_we_are_using);
    free(array);

    return 0;
}

int concatenate(char *source, int size, int counter, ...)
{
    if (size > 0 && counter > 0 && source != NULL)
    {
        va_list begin;
        va_start(begin, counter);

        char *our_main_storage = va_arg(begin, char *);
        int size_of_our_main_storage = (int) strlen(our_main_storage) + 1;
        if (size_of_our_main_storage <= size)
        {
            strcpy(source, our_main_storage);

            int temporary_storage = size_of_our_main_storage;
            for (int i = 0; i < counter - 1; i++)
            {
                char *we_are_using_this_now = va_arg(begin, char *);

                int size_of_we_using = (int) strlen(we_are_using_this_now) + 1;
                if (size >= size_of_we_using + temporary_storage)
                {
                    strcat(source, " ");
                    strcat(source, we_are_using_this_now);

                    temporary_storage = temporary_storage + size_of_we_using;
                }
                else
                {
                    va_end(begin);
                    return 2;
                }
            }
            va_end(begin);
            return 0;
        }
        va_end(begin);
        return 2;
    }
    return 1;
}
