#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destroy(char **words);
void display(char **words);
int create_leading_word_cross(const char *first, const char *second, char ***result);
int create_double_leading_word_cross(const char *first, const char *second, const char *third, const char *fourth, char ***result, char ***first_cross, char ***second_cross);

int main()
{
    int error;

    char *type_one = malloc(11 * sizeof(char));
    if(!type_one)
    {
        return printf("Failed to allocate memory"), 8;
    }

    char *type_two = malloc(11 * sizeof(char));
    if(!type_two)
    {
        return free(type_one), printf("Failed to allocate memory"), 8;
    }

    char *type_the = malloc(11 * sizeof(char));
    if(!type_the)
    {
        return free(type_one), free(type_two), printf("Failed to allocate memory"), 8;
    }

    char *type_fou = malloc(11 * sizeof(char));
    if(!type_fou)
    {
        return free(type_one), free(type_two), free(type_the), printf("Failed to allocate memory"), 8;
    }

    printf("Enter your words: ");

    error = scanf("%10s %10s %10s %10s", type_one, type_two, type_the, type_fou);
    if(error != 4)
    {
        return free(type_one), free(type_two), free(type_the), free(type_fou), printf("Incorrect input"), 1;
    }

    char **for_one;
    char **for_two;
    char **resulted;

    error = create_double_leading_word_cross(type_one, type_two, type_the, type_fou, &resulted, &for_one, &for_two);
    switch (error)
    {
        case 1:
            return free(type_one), free(type_two), free(type_the), free(type_fou), printf("Incorrect input"), 1;
        case 3:
            return free(type_one), free(type_two), free(type_the), free(type_fou), printf("Failed to allocate memory"), 8;
        case 2:
            return free(type_one), free(type_two), free(type_the), free(type_fou), printf("Unable to make two crosses"), 0;
    }

    display(for_one);
    printf("\n");
    display(for_two);
    printf("\n");
    display(resulted);

    return destroy(for_one), destroy(for_two), free(type_one), free(type_two), free(type_the), free(type_fou), destroy(resulted), 0;
}

int create_leading_word_cross(const char *first, const char *second, char ***result)
{
    if (result == NULL)
    {
        return -1;
    }
    if (first == NULL || second == NULL)
    {
        return *result = NULL, result = NULL, -1;
    }

    int dupka;

    dupka = 0;
    int pointer_on_one = 0;
    while (*(first + dupka) != '\0')
    {
        if (!(*(first + dupka) >= 'A' && *(first + dupka) <= 'Z'))
        {
            pointer_on_one =  1;
        }
        dupka++;
    }

    dupka = 0;
    int pointer_on_two = 0;
    while (*(second + dupka) != '\0')
    {
        if (!(*(second + dupka) >= 'A' && *(second + dupka) <= 'Z'))
        {
            pointer_on_two =  1;
        }
        dupka++;
    }

    if (pointer_on_one != 0 || pointer_on_two != 0)
    {
        return *result = NULL, result = NULL, -1;
    }

    int size_of_first = strlen(first);
    int size_of_second = strlen(second);

    int some_shitty_shit_yea_uwu = strcspn(second, first);
    if (some_shitty_shit_yea_uwu == size_of_second)
    {
        return *result = NULL, -2;
    }

    int variable_for_first_type = first - strchr(first, *(second + some_shitty_shit_yea_uwu));
    variable_for_first_type = abs(variable_for_first_type);

    char **resultik = calloc(size_of_first + 1, sizeof(char *));
    if (resultik == NULL)
    {
        return *result = NULL, result = NULL, -3;
    }

    int k, variable;
    for (int i = 0; i < size_of_first; i++)
    {
        if (i == variable_for_first_type)
        {
            variable = size_of_second;
        }
        else
        {
            variable = some_shitty_shit_yea_uwu + 1;
        }

        *(resultik + i) =  calloc(variable + 1, sizeof(char));
        if (*(resultik + i) == NULL)
        {
            for (k = 0; k < i; k++)
            {
                free(*(resultik + k));
            }
            return free(resultik), *result = NULL, result = NULL, -3;
        }
    }
    *(resultik + size_of_first) = NULL;

    for (int i = 0; i < size_of_first; i++)
    {
        if (i == variable_for_first_type)
        {
            int j;
            variable = size_of_second;
            for (j = 0; j < variable; j++)
            {
                *(*(resultik + i) + j) = *(second + j);
            }
            *(*(resultik + i) + j) = '\0';
        }
        else
        {
            int j;
            variable = some_shitty_shit_yea_uwu + 1;
            for (j = 0; j < variable - 1; j++)
            {
                *(*(resultik + i) + j) = ' ';
            }
            *(*(resultik + i) + j) = *(first + i);
            *(*(resultik + i) + j + 1) = '\0';
        }
    }

    *result = resultik;
    return variable_for_first_type;
}
void destroy(char **words)
{
    if (words == NULL)
    {
        return;
    }
    for (int i = 0; *(words + i) != NULL; i++)
    {
        free(*(words + i));
    }
    free(words);
}
void display(char **words)
{
    if (words == NULL)
    {
        return;
    }
    for (int i = 0; *(words + i) != NULL; i++)
    {
        printf("%s\n", *(words + i));
    }
}
int create_double_leading_word_cross(const char *first, const char *second, const char *third, const char *fourth, char ***result, char ***first_cross, char ***second_cross)
{
    if (result == NULL)
    {
        return 1;
    }

    int temporary_shit_for_one = create_leading_word_cross(second, first, first_cross);
    if (temporary_shit_for_one < 0)
    {
        return *result = NULL, result = NULL, abs(temporary_shit_for_one);
    }

    int temporary_shit_for_two = create_leading_word_cross(fourth, third, second_cross);
    if (temporary_shit_for_two < 0)
    {
        return *result=NULL, result=NULL, destroy(*first_cross), abs(temporary_shit_for_two);
    }

    char **working_on_that_one = *first_cross;
    char **working_on_that_two = *second_cross;

    int size_for_one = 0;
    int size_for_two = 0;

    for(; *(working_on_that_one + size_for_one) != NULL ;)
    {
        size_for_one++;
    }
    for(; *(working_on_that_two + size_for_two) != NULL ;)
    {
        size_for_two++;
    }

    int variable_one;
    if (temporary_shit_for_one > temporary_shit_for_two)
    {
        variable_one = temporary_shit_for_one - temporary_shit_for_two;
    }
    else
    {
        variable_one = temporary_shit_for_two - temporary_shit_for_one;
    }

    int variable_two;
    if (temporary_shit_for_one > temporary_shit_for_two)
    {
        variable_two = temporary_shit_for_one;
    }
    else
    {
        variable_two = temporary_shit_for_two;
    }

    if (strlen(second) - temporary_shit_for_one > strlen(fourth) - temporary_shit_for_two)
    {
        variable_two = variable_two + (int) strlen(second) - temporary_shit_for_one;
    }
    else
    {
        variable_two = variable_two + (int) strlen(fourth) - temporary_shit_for_two;
    }

    char **resultik = calloc(variable_two + 1, sizeof(char *));
    if (resultik == NULL)
    {
        return destroy(working_on_that_one), destroy(working_on_that_two), *result = NULL, result = NULL, 3;
    }
    *(resultik + variable_two) = NULL;

    int index;

    int using_number = strlen(*(working_on_that_one + temporary_shit_for_one));

    if (temporary_shit_for_one > temporary_shit_for_two)
    {
        for (index = 0; index < temporary_shit_for_one - temporary_shit_for_two; index++)
        {
            *(resultik + index) = calloc(strlen(*(working_on_that_one + index)) + 1, sizeof(char));

            if (*(resultik + index) == NULL)
            {
                for (int t = 0; t < index; t++)
                {
                    free(*(resultik + t));
                }
                return destroy(working_on_that_one), destroy(working_on_that_two), free(resultik), *result = NULL, result = NULL, 3;
            }
        }
        for(; index < variable_two; index++)
        {
            int temp_shit;

            if (index - variable_one < size_for_two)
            {
                temp_shit = strlen(*(working_on_that_two + index - variable_one));
            }
            else
            {
                temp_shit = -3;

                using_number = strlen(*(working_on_that_one + index));
            }

            *(resultik + index) = calloc(using_number + temp_shit + 4, sizeof(char));

            if (*(resultik + index) == NULL)
            {
                for (int t = 0; t < index; t++)
                {
                    free(*(resultik + t));
                }
                return destroy(working_on_that_one), destroy(working_on_that_two), free(resultik), *result = NULL, result = NULL, 3;
            }
        }
    }
    else if (temporary_shit_for_two > temporary_shit_for_one)
    {
        for(index = 0; index < temporary_shit_for_two - temporary_shit_for_one; index++)
        {
            int temp_shit;

            if (index < size_for_two)
            {
                temp_shit = strlen(*(working_on_that_two + index));
            }
            else
            {
                temp_shit = -3;

                using_number = strlen(*(working_on_that_one + index));
            }

            *(resultik + index) = calloc(using_number + temp_shit + 4, sizeof(char));

            if (*(resultik + index) == NULL)
            {
                for (int t = 0; t < index; t++)
                {
                    free(*(resultik + t));
                }
                return destroy(working_on_that_one), destroy(working_on_that_two), free(resultik), *result = NULL, result = NULL, 3;
            }

        }
        for(; index < variable_two; index++)
        {
            int temp_shit;
            if (index < size_for_two)
            {
                temp_shit = strlen(*(working_on_that_two + index));
            }
            else
            {
                temp_shit = -3;

                using_number = strlen(*(working_on_that_one + index - variable_one));
            }

            *(resultik + index) = calloc(using_number + temp_shit + 4, sizeof(char));

            if (*(resultik + index) == NULL)
            {
                for (int t = 0; t < index; t++)
                {
                    free(*(resultik + t));
                }
                return destroy(working_on_that_one), destroy(working_on_that_two), free(resultik), *result = NULL, result = NULL, 3;
            }
        }
    }
    else
    {
        for(index = 0; index < variable_two; index++)
        {
            int temp_shit;

            if (index < size_for_two)
            {
                temp_shit = strlen(*(working_on_that_two + index));
            }
            else
            {
                temp_shit = -3;

                using_number = strlen(*(working_on_that_one + index));
            }

            *(resultik + index) = calloc(using_number + temp_shit + 4, sizeof(char));

            if (*(resultik + index) == NULL)
            {
                for (int t = 0; t < index; t++)
                {
                    free(*(resultik + t));
                }
                return destroy(working_on_that_one), destroy(working_on_that_two), free(resultik), *result = NULL, result = NULL, 3;
            }
        }
    }

    int some_interesting_storage = 0;

    using_number = strlen(*(working_on_that_one + temporary_shit_for_one));

    if (temporary_shit_for_one <= temporary_shit_for_two)
    {
        if (temporary_shit_for_two > temporary_shit_for_one)
        {
            for (index = 0; index < temporary_shit_for_two - temporary_shit_for_one; index++)
            {
                for (int t = 0; t < using_number; t++)
                {
                    strcat(*(resultik + index), " ");
                }
                strcat(*(resultik + index), "   ");

                strcat(*(resultik + index), *(working_on_that_two + index));
            }
            for (; index < variable_two; index++)
            {
                if (*(working_on_that_one + index - variable_one) != NULL)
                {
                    strcat(*(resultik + index), *(working_on_that_one + index - variable_one));

                    if (index >= size_for_two) continue;

                    for (int t = strlen(*(working_on_that_one + index - variable_one)); t < using_number; t++)
                    {
                        strcat(*(resultik + index), " ");
                    }
                    strcat(*(resultik + index), "   ");

                    strcat(*(resultik + index), *(working_on_that_two + index));
                }
                else
                {
                    some_interesting_storage = 1;

                    break;
                }
            }
        }
        else
        {
            for (index = 0; index < variable_two; index++)
            {
                if (*(working_on_that_one + index) != NULL)
                {
                    strcat(*(resultik + index), *(working_on_that_one + index));

                    if (index >= size_for_two) continue;

                    for (int t = strlen(*(working_on_that_one + index)); t < using_number; t++)
                    {
                        strcat(*(resultik + index), " ");
                    }

                    strcat(*(resultik + index), "   ");

                    strcat(*(resultik + index), *(working_on_that_two + index));
                }
                else
                {
                    some_interesting_storage = 1;

                    break;
                }
            }
        }
    }
    else
    {
        for (index = 0; index < temporary_shit_for_one - temporary_shit_for_two; index++)
        {
            strcat(*(resultik + index), *(working_on_that_one + index));
        }

        for (; index < variable_two; index++)
        {
            if (*(working_on_that_one + index) == NULL)
            {
                some_interesting_storage = 1;

                break;
            }
            strcat(*(resultik + index), *(working_on_that_one + index));

            if (index - variable_one < size_for_two)
            {
                for (int t = strlen(*(working_on_that_one + index)); t < using_number; t++)
                {
                    strcat(*(resultik + index), " ");
                }

                strcat(*(resultik + index), "   ");

                strcat(*(resultik + index), *(working_on_that_two + index - variable_one));
            }
        }
    }

    if(some_interesting_storage == 1)
    {
        for(; index < variable_two; index++)
        {
            for (int t = 0; t < using_number; t++)
            {
                strcat(*(resultik + index), " ");
            }

            strcat(*(resultik + index), "   ");

            if(temporary_shit_for_one <= temporary_shit_for_two)
            {
                variable_one = 0;
            }

            strcat(*(resultik + index), *(working_on_that_two + index - variable_one));
        }
    }

    return *result = resultik, 0;
}
