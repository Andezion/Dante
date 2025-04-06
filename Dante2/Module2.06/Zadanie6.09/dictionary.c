#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dictionary.h"

struct dictionary_t* create_dictionary(int N, int *err_code)
{
    if (N <= 0)
    {
        if(err_code)
        {
            *err_code = 1;
        }
        return NULL;
    }

    struct dictionary_t *p = malloc(sizeof(struct dictionary_t));
    if (p == NULL)
    {
        if(err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    p->size = 0;
    p->capacity = N;
    p->wc = malloc(N * sizeof(struct word_count_t));
    if (p->wc == NULL)
    {
        free(p);
        if(err_code)
        {
            *err_code = 2;
        }
        return NULL;
    }

    if(err_code)
    {
        *err_code = 0;
    }
    return p;
}

void destroy_dictionary(struct dictionary_t** d)
{
    if (d == NULL)
    {
        return;
    }

    if ((*d)->wc)
    {
        for (int i = 0; i < (*d)->size; i++)
        {
            free(((*d)->wc + i)->word);
        }
        free((*d)->wc);
    }
    free(*d);
}

struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word)
{
    if (d == NULL || word == NULL || d->capacity < d->size || d->wc == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < d->size; i++)
    {
        if (strcmp(word, (d->wc + i)->word) == 0)
        {
            return (d->wc + i);
        }
    }

    return NULL;
}

void dictionary_display(const struct dictionary_t *d)
{
    if (d == NULL || d->wc == NULL || d->size < 0 || d->capacity <= 0 || d->size > d->capacity)
    {
        return;
    }

    for(int i = 0; i < d->size; i++)
    {
        printf("%s %d\n", (d->wc +i)->word, (d->wc + i)->counter);
    }
}

int dictionary_add_word(struct dictionary_t *d, const char *word)
{
    if (d == NULL || d->capacity < 1 || d->size < 0 || d->wc == NULL
        || word == NULL || d->size > d->capacity)
    {
        return 1;
    }

    struct word_count_t *some_shitty_shit = NULL;
    struct word_count_t *working_place = dictionary_find_word(d, word);

    if (working_place != NULL)
    {
        working_place->counter++;
    }
    else
    {
        if (d->size == d->capacity)
        {
            some_shitty_shit = realloc(d->wc, sizeof(struct word_count_t) * 2 * d->capacity);
            if (some_shitty_shit == NULL)
            {
                return 2;
            }

            d->wc = some_shitty_shit;
            d->capacity = d->capacity * 2;
        }

        int some_size = (int)strlen(word);
        (d->wc + d->size)->word = malloc((some_size + 1) * sizeof(char));
        if ((d->wc + d->size)->word == NULL)
        {
            return 2;
        }

        strcpy((d->wc + d->size)->word, word);

        *((d->wc + d->size)->word + some_size) = '\0';
        (d->wc + d->size)->counter = 1;
        d->size = d->size + 1;
    }

    return 0;
}
