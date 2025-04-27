#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *lower_to_upper(const char *in)
{
    if (in == NULL)
    {
        return NULL;
    }

    char *temp_shit = malloc((strlen(in) + 1) * sizeof(char));
    if (temp_shit == NULL)
    {
        return NULL;
    }

    strcpy(temp_shit, in);

    for (int i = 0; *(in + i) != '\0'; i++)
    {
        if (islower(*(in + i)))
        {
            *(temp_shit + i) = (char) toupper(*(temp_shit + i));
        }
    }
    return temp_shit;
}

char *upper_to_lower(const char *in)
{
    if (in == NULL)
    {
        return NULL;
    }

    char *temp_shit = malloc((strlen(in) + 1) * sizeof(char));
    if (temp_shit == NULL)
    {
        return NULL;
    }

    strcpy(temp_shit, in);

    for (int i = 0; *(in + i) != '\0'; i++)
    {
        if (!islower(*(in + i)))
        {
            *(temp_shit + i) = (char) tolower(*(temp_shit + i));
        }
    }
    return temp_shit;
}

char *space_to_dash(const char *in)
{
    if (in == NULL)
    {
        return NULL;
    }

    char *temp_shit = malloc((strlen(in) + 1) * sizeof(char));
    if (temp_shit == NULL)
    {
        return NULL;
    }

    strcpy(temp_shit, in);

    for (int i = 0; *(in + i) != '\0'; i++)
    {
        if (*(in + i) == ' ')
        {
            *(temp_shit + i) = '_';
        }
    }
    return temp_shit;
}

char *reverse_letter(const char *in)
{
    if (in == NULL)
    {
        return NULL;
    }
    char *temp_shit = malloc((strlen(in) + 1) * sizeof(char));
    if (temp_shit == NULL)
    {
        return NULL;
    }

    strcpy(temp_shit, in);

    for (int i = 0; *(in + i) != '\0'; i++)
    {
        if (isupper(*(in + i)))
        {
            *(temp_shit + i) = 'Z' - ((*(in + i)) - 'A');
        }
        if (islower(*(in + i)))
        {
            *(temp_shit + i) = 'z' - ((*(in + i)) - 'a');
        }
    }
    return temp_shit;
}

void free_texts(char **text)
{
    if (text == NULL)
    {
        return;
    }

    for (int i = 0; *(text + i) != NULL; i++)
    {
        free(*(text + i));
    }
    free(text);
}
