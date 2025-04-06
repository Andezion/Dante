#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char **split_words(const char *text);
int sort_words(char **words);
void destroy(char **words);

int main()
{
    char *text = malloc(sizeof(char) * 1000);
    if(text == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter: ");
    scanf("%999[^\n]",text);
    while(getchar() != '\n');

    int i = 0;
    int pointer = 0;
    while(*(text + i))
    {
        if(isalpha(*(text + i)))
        {
            pointer = 1;
        }
        i++;
    }
    if(pointer == 0)
    {
        printf("Nothing to show");
        free(text);
        return 0;
    }

    char **resulted = split_words(text);
    if (resulted == NULL)
    {
        printf("Failed to allocate memory");
        free(text);
        return 8;
    }

    int error = sort_words(resulted);
    if(error == 1)
    {
        printf("Can't sort in normally");
        return 666;
    }

    for (int j = 0; *(resulted + j); j++)
    {
        printf("%s\n", *(resulted + j));
    }

    destroy(resulted);
    free(text);

    return 0;
}

char **split_words(const char *text)
{
    if (text == NULL || strlen(text) == 0)
    {
        return NULL;
    }

    char **temp_data = calloc(1, sizeof(char *));
    if (temp_data == NULL)
    {
        return NULL;
    }

    int counter = 0;
    int some_length = 0;
    for (int i = 0 ;; i++)
    {
        if (isalpha(*(text + i)) != 0)
        {
            some_length++;
        }
        else
        {
            if (!isalpha(*(text + i)) && some_length > 0)
            {
                char **hehe_i_love_you = realloc(temp_data, sizeof(char *) * (counter + 2));
                if (hehe_i_love_you != NULL)
                {
                    temp_data = hehe_i_love_you;

                    *(temp_data + counter) = calloc(some_length + 1, sizeof(char));
                    if (*(temp_data + counter) != NULL)
                    {
                        counter++;
                        some_length = 0;
                    }
                    else
                    {
                        destroy(temp_data);
                        return NULL;
                    }
                }
                else
                {
                    *(temp_data + counter) = NULL;
                    destroy(temp_data);
                    return NULL;
                }
            }
        }
        if (*(text + i) == '\0')
        {
            break;
        }
    }
    if (counter == 0)
    {
        free(temp_data);
        return NULL;
    }

    *(temp_data + counter) = NULL;

    counter = 0;
    some_length = 0;
    for (int i = 0; *(text + i); i++)
    {
        if (!isalpha(*(text + i))) {}
        else
        {
            *(*(temp_data + counter) + some_length++) = *(text + i);
        }

        if (isalpha(*(text + i)) || some_length <= 0)
        {
            continue;
        }
        *(*(temp_data + counter++) + some_length) = '\0';
        some_length = 0;
    }

    return temp_data;
}
int sort_words(char **words)
{
    if(words == NULL)
    {
        return 1;
    }

    int temp = 0;
    while(*(words + temp))
    {
        temp++;
    }

    int i = 0;
    while(i < temp)
    {
        int j = 0;
        while(j < temp - 1)
        {
            if(strcmp(*(words + j), *(words + j + 1)) > 0)
            {
                char *dupka = *(words + j);
                *(words + j) = *(words + j + 1);
                *(words + j + 1)  = dupka;
            }
            j++;
        }
        i++;
    }

    return 0;
}
void destroy(char **words)
{
    if(words == NULL)
    {
        return;
    }

    for(int i = 0; *(words + i) != NULL; i++)
    {
        free(*(words + i));
    }
    free(words);
}
