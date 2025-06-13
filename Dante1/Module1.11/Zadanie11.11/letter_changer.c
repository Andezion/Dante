#include <stdio.h>
#include "letter_changer.h"

char* change_letter_size(char *txt, enum letter_changer_t c)
{
    if(txt == NULL)
    {
        return NULL;
    }

    if(c == TO_UPPER || c == 'b' || c == 'B')
    {
        for(int i = 0; *(txt + i) != '\0'; i++)
        {
            *(txt + i) = to_upper(*(txt + i));
        }
    }
    else if(c == TO_LOWER || c == 's' || c == 'S')
    {
        for(int i = 0; *(txt + i) != '\0'; i++)
        {
            *(txt + i) = to_lower(*(txt + i));
        }
    }

    return txt;
}

char to_lower(char letter)
{
    if(letter >= 'A' && letter <= 'Z')
    {
        letter = letter + ('a' - 'A');
    }
    return letter;
}

char to_upper(char letter)
{
    if(letter >= 'a' && letter <= 'z')
    {
        letter = letter - ('a' - 'A');
    }
    return letter;
}
