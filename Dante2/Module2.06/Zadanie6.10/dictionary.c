#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

int my_strcmp(const char *word1, const char *word2)
{
    int i = 0;
    while(*(word1 + i) && *(word2 + i))
    {

        if( (*(word1 + i) >= 'A' && *(word1 + i)<= 'Z') && (*(word2 + i) >= 'A' && *(word2 + i) <= 'Z'))
        {
            if (*(word1 + i) > *(word2 + i))
            {
                return 2;
            }
            if(*(word1 + i) < *(word2 + i))
            {
                return 1;
            }
        }
        if ((*(word1 + i) >= 'a' && *(word1 + i) <= 'z') && (*(word2 + i) >= 'a' && *(word2 + i) <= 'z'))
        {
            if (*(word1 + i) > *(word2 + i))
            {
                return 2;
            }
            if (*(word1 + i) < *(word2 + i))
            {
                return 1;
            }
        }
        if ((*(word1 + i) >= 'A' && *(word1 + i) <= 'Z') && (*(word2 + i) >= 'a' && *(word2 + i) <= 'z'))
        {
            return 1;
        }
        if ((*(word1 + i) >= 'a' && *(word1 + i) <= 'z') && (*(word2 + i) >= 'A' && *(word2 + i) <= 'Z'))
        {
            return 2;
        }
        i++;
    }

    if (((*(word1 + i) == '\0')) && (*(word2 + i) == '\0'))
    {
        return 0;
    }
    if (*(word1 + i) == '\0')
    {
        return 1;
    }
    if (*(word2 + i) == '\0')
    {
        return 2;
    }

    return 0;

}

void swapper(char *word1, char *word2, int num1, int num2)
{
    char *temporary = word1;
    word1 = word2;
    word2 = temporary;

    int dupka = num1;
    num1 = num2;
    num2 = dupka;
}

int dictionary_sort_alphabetically(struct dictionary_t *d)
{
    if (d == NULL || d->capacity < d->size || d->wc == NULL || d->size <= 0)
    {
        return 1;
    }

    int temp;
    for(int i = 0; i < d->size - 1; i++)
    {
        temp = 0;
        for(int j = 0; j < d->size - i - 1; j++)
        {
            if(my_strcmp((d->wc + j)->word, (d->wc + j + 1)->word) == 2)
            {
                char *temporary = (d->wc + j)->word;
                (d->wc + j)->word = (d->wc + j + 1)->word;
                (d->wc + j + 1)->word = temporary;

                int dupka = (d->wc + j)->counter;
                (d->wc + j)->counter = (d->wc + j + 1)->counter;
                (d->wc + j + 1)->counter = dupka;

                temp = 1;
            }
        }
        if(temp == 0)
        {
            break;
        }
    }

    return 0;
}

int dictionary_sort_occurence(struct dictionary_t *d)
{
    if (d == NULL || d->capacity < d->size || d->wc == NULL || d->size <= 0)
    {
        return 1;
    }

    int change;
    for (int i = 0; i < d->size - 1; i++)
    {
        change = 0;
        for (int j = 0; j < d->size - i - 1; j++)
        {
            if ((d->wc + j)->counter  <  (d->wc + j + 1)->counter)
            {
                char *temporary = (d->wc + j)->word;
                (d->wc + j)->word = (d->wc + j + 1)->word;
                (d->wc + j + 1)->word = temporary;

                int dupka = (d->wc + j)->counter;
                (d->wc + j)->counter = (d->wc + j + 1)->counter;
                (d->wc + j + 1)->counter = dupka;

                change = 1;
            }

            if((d->wc + j)->counter  ==  (d->wc + j + 1)->counter)
            {
                if (my_strcmp((d->wc + j)->word, (d->wc + j + 1)->word) == 2)
                {
                    char *temporary = (d->wc + j)->word;
                    (d->wc + j)->word = (d->wc + j + 1)->word;
                    (d->wc + j + 1)->word = temporary;

                    int dupka = (d->wc + j)->counter;
                    (d->wc + j)->counter = (d->wc + j + 1)->counter;
                    (d->wc + j + 1)->counter = dupka;

                    change = 1;
                }
            }
        }

        if (change == 0)
        {
            break;
        }
    }

    return 0;
}

int save_dictionary_b(const struct dictionary_t *d, const char *filename)
{
    if (d == NULL || d->capacity < d->size || d->wc == NULL || d->size <= 0 || filename == NULL)
    {
        return 1;
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return 2;
    }

    fwrite(&d->size, sizeof(int), 1, file);
    for(int i = 0 ; i < d->size ; i ++)
    {
        int size = (int)strlen((d->wc + i)->word);

        fwrite(&size, sizeof(int), 1, file);
        fwrite((d->wc + i)->word, size, 1, file);
        fwrite(&(d->wc + i)->counter, sizeof(int), 1, file);
    }

    fclose(file);
    return 0;
}

struct dictionary_t* load_dictionary_b(const char *filename, int *err_code)
{
    int error;

    if (filename != NULL)
    {
        struct dictionary_t *dict = malloc(sizeof(struct dictionary_t));
        if (dict == NULL)
        {
            if (err_code != NULL)
            {
                *err_code = 4;
            }
            return NULL;
        }

        FILE *file = fopen(filename, "rb");
        if (file != NULL)
        {
            if (strstr(filename, ".txt"))
            {
                if (err_code == NULL) {}
                else
                {
                    *err_code = 3;
                }

                free(dict);
                fclose(file);

                return NULL;
            }

            error = (int) fread(&dict->size, sizeof(int), 1, file);
            if (error == 0 || dict->size <= 0)
            {
                if (err_code != NULL)
                {
                    *err_code = 3;
                }

                fclose(file);
                free(dict);

                return NULL;
            }

            dict->capacity = dict->size;
            dict->wc = malloc(sizeof(struct word_count_t) * dict->size);
            if (dict->wc == NULL)
            {
                if (err_code != NULL)
                {
                    *err_code = 4;
                }

                fclose(file);
                free(dict);

                return NULL;
            }
            dict->size = 0;

            for (int i = 0; i < dict->capacity; dict->size++, i++)
            {
                int temp_shit;
                error = (int) fread(&temp_shit, sizeof(int), 1, file);
                if (error != 0 && temp_shit > 0)
                {
                    (dict->wc + i)->word = malloc(temp_shit + 1);
                    if ((dict->wc + i)->word != NULL)
                    {
                        *((dict->wc + i)->word + temp_shit) = 0;
                        error = (int) fread((dict->wc + i)->word, temp_shit, 1, file);
                        if (error != 0)
                        {
                            error = (int) fread(&(dict->wc + i)->counter, sizeof(int), 1, file);
                            if (error != 0 && (dict->wc + i)->counter > 0)
                            {
                                continue;
                            }
                            if (err_code != NULL)
                            {
                                *err_code = 3;
                            }

                            fclose(file);
                            destroy_dictionary(&dict);

                            return NULL;
                        }
                        else
                        {
                            if (err_code != NULL)
                            {
                                *err_code = 3;
                            }

                            fclose(file);
                            destroy_dictionary(&dict);

                            return NULL;
                        }
                    }
                    else
                    {
                        if (err_code != NULL)
                        {
                            *err_code = 4;
                        }

                        fclose(file);
                        destroy_dictionary(&dict);

                        return NULL;
                    }
                }
                else
                {
                    if (err_code != NULL)
                    {
                        *err_code = 3;
                    }

                    fclose(file);
                    destroy_dictionary(&dict);

                    return NULL;
                }
            }

            if (err_code)
            {
                *err_code = 0;
            }

            fclose(file);

            return dict;
        }
        else
        {
            if (err_code != NULL)
            {
                *err_code = 2;
            }

            free(dict);

            return NULL;
        }
    }
    else
    {
        if (err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }
}

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
    if (d == NULL || *d == NULL)
    {
        return;
    }

    for (int i = 0; i < (*d)->size; i++)
    {
        if (((*d)->wc + i)->word != NULL)
        {
            free(((*d)->wc + i) -> word);
        }
    }

    if ((*d)->wc!=NULL)
    {
        free((*d)->wc);
    }
    if ((*d) != NULL)
    {
        free(*d);
    }
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
