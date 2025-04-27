#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"


typedef char * (* func) (const char *);

char **text_modifier(const char *text, int N, ...);

int main()
{
    int error;

    char *our_text = malloc(1001 * sizeof(char));
    if(our_text == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    func *operations = malloc(4 * sizeof(func *));
    if(operations == NULL)
    {
        return free(our_text), printf("Failed to allocate memory"), 8;
    }

    int *damn_what_is_this = malloc(4 * sizeof(int));
    if(damn_what_is_this == NULL)
    {
        return free(our_text), free(operations), printf("Failed to allocate memory"), 8;
    }

    printf("Enter data: ");
    scanf("%1000[^\n]", our_text);

    while(getchar() != '\n');

    int number;
    printf("Enter number: ");
    error = scanf("%i",&number);
    if(error != 1)
    {
        return free(our_text), free(operations), free(damn_what_is_this), printf("Incorrect input"), 1;
    }
    if(number > 4 || number < 2)
    {
        return free(our_text), free(operations), free(damn_what_is_this), printf("Incorrect input data"), 2;
    }

    while(getchar() != '\n');

    printf("Enter numbers: ");

    int x = 0;
    while(x < number)
    {
        error = scanf("%i",&*(damn_what_is_this + x));
        if(error != 1)
        {
            return free(our_text), free(operations), free(damn_what_is_this), printf("Incorrect input"), 1;
        }
        x++;
    }

    char **i_dont_know_what_to_do;

    int i = 0;
    while(i < number)
    {
        if(*(damn_what_is_this + i) == 0)
        {
            i_dont_know_what_to_do=text_modifier(our_text, 1, lower_to_upper);

            if(i_dont_know_what_to_do == NULL)
            {
                return free(our_text), free(operations), free(damn_what_is_this), printf("Failed to allocate memory"), 8;
            }

            printf("%s\n",*i_dont_know_what_to_do);
        }
        if(*(damn_what_is_this + i) == 1)
        {
            i_dont_know_what_to_do=text_modifier(our_text, 1, upper_to_lower);

            if(i_dont_know_what_to_do == NULL)
            {
                return free(our_text), free(operations), free(damn_what_is_this), printf("Failed to allocate memory"), 8;
            }

            printf("%s\n",*i_dont_know_what_to_do);
        }
        if(*(damn_what_is_this + i) == 2)
        {
            i_dont_know_what_to_do=text_modifier(our_text, 1, reverse_letter);

            if(i_dont_know_what_to_do == NULL)
            {
                return free(our_text), free(operations), free(damn_what_is_this), printf("Failed to allocate memory"), 8;
            }

            printf("%s\n",*i_dont_know_what_to_do);
        }
        if(*(damn_what_is_this + i) == 3)
        {
            i_dont_know_what_to_do=text_modifier(our_text, 1, space_to_dash);
            if(i_dont_know_what_to_do == NULL)
            {
                return free(our_text), free(operations), free(damn_what_is_this), printf("Failed to allocate memory"), 8;
            }
            printf("%s\n",*i_dont_know_what_to_do);
        }
        free_texts(i_dont_know_what_to_do);
        i++;
    }

    return free(our_text), free(operations), free(damn_what_is_this), 0;
}

char **text_modifier(const char *text, int N, ...)
{
    if (text == NULL || N <= 0)
    {
        return NULL;
    }

    char **dupochka = malloc((N + 1) * sizeof(char *));
    if (dupochka == NULL)
    {
        return NULL;
    }
    *(dupochka + N) = NULL;

    va_list begin;
    va_start(begin, N);

    for (int i = 0; i < N; i++)
    {
        func arg = va_arg(begin, func);

        *(dupochka + i) = arg(text);
        if (*(dupochka + i) == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                free(*(dupochka + j));
            }
            free(dupochka);
            return NULL;
        }
    }

    va_end(begin);
    return dupochka;
}
