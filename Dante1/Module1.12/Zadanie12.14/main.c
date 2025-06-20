#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int distance(const char tab[]);

int main()
{
    const int max_words = 10;
    const int max_length = 2000;
    char words[10][2001];
    int word_count = 0;

    printf("Enter:\n");

    while (1)
    {
        if (fgets(words[word_count], max_length + 1, stdin) == NULL)
        {
            break;
        }

        int len = (int)strlen(words[word_count]);
        if (len > 0 && words[word_count][len - 1] == '\n')
        {
            words[word_count][len - 1] = '\0';
            len--;
        }

        if (len == 0)
        {
            break;
        }

        if (len > max_length)
        {
            printf("Incorrect input data\n");
            return 2;
        }

        for (int i = 0; words[word_count][i] != '\0'; ++i)
        {
            if (words[word_count][i] < 'A' || words[word_count][i] > 'Z')
            {
                printf("Incorrect input data\n");
                return 2;
            }
        }

        word_count++;
        if (word_count >= max_words)
        {
            break;
        }
    }

    for (int i = 0; i < word_count; i++)
    {
        int result = distance(words[i]);
        if (result == -1)
        {
            printf("Incorrect input data\n");
            return 2;
        }
        printf("%i\n", result);
    }
    return 0;
}

int distance(const char tab[])
{
    if(tab == NULL)
    {
        return -1;
    }

    for(size_t i = 0; i < strlen(tab); i++)
    {
        if(isalpha(tab[i]))
        {
            if(isupper(tab[i]))
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    int counter = 0;

    for(size_t i = 0; i < strlen(tab) - 1; i++)
    {
        for(size_t j = i + 1; j < strlen(tab); j++)
        {
            if(abs(tab[i] - tab[j]) > counter)
            {
                counter = abs(tab[i] - tab[j]);
            }
        }
    }

    return counter;
}
