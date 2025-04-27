#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int my_strlen(char *word)
{
    int i = 0;
    while(*(word + i) != '\0')
    {
        i++;
    }
    return i;
}

int my_checker(char storage)
{
    if(storage == ' ' || storage == '\n' || storage == '.' || storage == ',' || storage == '\'')
    {
        return 1;
    }
    return 0;
}

int *count_words(const char *filename, int *err_code, int N, ...);

int main(int argc, char *argv[])
{
    if(argc <= 2)
    {
        printf("Not enough arguments");
        return 9;
    }

    int error;
    int i = 0;
    int *resultik;
    while(i < argc - 2)
    {
        resultik = count_words(*(argv + 1), &error, 1, *(argv + i + 2));

        switch (error)
        {
            case 2:
                printf("Couldn't open file");
                return 4;
            case 3:
                printf("Failed to allocate memory");
                return 8;
        }

        printf("%i\n", *resultik); free(resultik);

        i++;
    }

    return 0;
}

int *count_words(const char *filename, int *err_code, int N, ...)
{
    if (filename == NULL || N < 1)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    FILE *file = fopen(filename, "rt");
    if (file == NULL)
    {
        if (err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    int *array = calloc(N, sizeof(int));
    if (array == NULL)
    {
        if (err_code)
        {
            *err_code = 3;
        }
        fclose(file);
        return NULL;
    }

    va_list begin;
    va_start(begin, N);

    for (int i = 0; i < N; ++i)
    {
        char *temp_helper = va_arg(begin, char *);
        int new_temp_helper = strlen(temp_helper);

        int storage;
        int comp_shit_helper = 0;

        while ((storage = fgetc(file)) != EOF)
        {
            if (comp_shit_helper >= new_temp_helper)
            {
                comp_shit_helper = 0;

                if (storage == ' ' || storage == '\n' || storage == '.' || storage == ',' || storage == '\'' || storage == EOF)
                {
                    *(array + i) = *(array + i) + 1;
                }

                if (storage != ' ' && storage != '\n')
                {
                    while ((storage = fgetc(file)) != EOF && storage != ' ' && storage != '\n');
                }
            }
            else
            {
                if (comp_shit_helper == 0)
                {
                    switch (storage)
                    {
                        case '"':
                        case '\n':
                        case 91:
                        case '-':
                        case '(':
                            continue;
                        default:
                            break;
                    }
                }
                if (storage == *(temp_helper + comp_shit_helper))
                {
                    comp_shit_helper++;
                }
                else
                {
                    if (storage == ' ' || storage == '\n')
                    {
                        comp_shit_helper = 0;
                    }
                    else
                    {
                        while ((storage = fgetc(file)) != EOF && storage != ' ' && storage != '\n');
                        comp_shit_helper = 0;
                    }
                }
            }
        }
        rewind(file);
    }

    va_end(begin);
    fclose(file);

    if (err_code)
    {
        *err_code = 0;
    }

    return array;
}

