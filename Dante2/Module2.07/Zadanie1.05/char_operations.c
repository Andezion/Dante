#include "char_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* letter_modifier(const char* input_text, char (*fun)(char))
{
    if(input_text == NULL || fun == NULL)
    {
        return NULL;
    }

    size_t shit = strlen(input_text);
    char *data = malloc((shit + 1) * sizeof(char));
    if(data == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < shit; ++i)
    {
        *(data + i) = fun(*(input_text + i));
    }

    *(data + shit) = '\0';

    return data;
}

char lower_to_upper(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        ch -= ' ';
    }
    return ch;
}

char upper_to_lower(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
    {
        ch += ' ';
    }
    return ch;
}

char space_to_dash(char ch)
{
    if(ch == ' ')
    {
        ch = '_';
    }
    return ch;
}
char reverse_letter(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        ch = 'z' - ch + 'a';
    }
    if(ch >= 'A' && ch <= 'Z')
    {
        ch = 'Z' - ch + 'A';
    }
    return ch;
}
