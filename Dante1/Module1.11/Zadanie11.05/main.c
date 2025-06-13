#include <stdio.h>
#include <malloc.h>

int my_strlen(char const *text)
{
    int size = 0;

    while(*(text + size) != '\0')
    {
        size++;
    }

    return size;
}

char* reverse(char* text)
{
    if(text == NULL)
    {
        return NULL;
    }

    int size = my_strlen(text);
    if (size <= 1)
    {
        return text;
    }

    int i = 0;
    int j = size - 1;

    while (i < j)
    {
        char temp = *(text + i);
        *(text + i) = *(text + j);
        *(text + j) = temp;

        i++;
        j--;
    }


    return text;
}

char* remove_non_letters(char* text)
{
    if(text == NULL)
    {
        return NULL;
    }

    int size = my_strlen(text);

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(('a' <= *(text + i) && *(text + i) <= 'z') || ('A' <= *(text + i) && *(text + i) <= 'Z')))
        {
            *(text + j) = ' ';
            j++;
        }
        else
        {
            *(text + j) = *(text + i);
            j++;
        }
    }
    *(text + j) = '\0';

    return text;
}

char* trim(char* text)
{
    if (text == NULL)
    {
        return NULL;
    }

    int size = my_strlen(text);
    char *result = malloc(size + 1);
    if (result == NULL)
    {
        return NULL;
    }

    int i, j = 0;
    int pointer = 0;

    for (i = 0; i < size; i++)
    {
        if (*(text + i) != ' ')
        {
            *(result + j) = *(text + i);
            j++;
            pointer = 0;
        }
        else if (!pointer)
        {
            *(result + j) = ' ';
            j++;
            pointer = 1;
        }
    }
    *(result + j) = '\0';

    if (j > 0 && *(result + j - 1) == ' ')
    {
        *(result + j - 1) = '\0';
    }

    return result;
}


int main()
{
    char text[1001];

    printf("Enter: ");
    scanf("%1000[^\n]",text);

    int pointer = 0;
    int i = 0;
    while(*(text + i) != '\0')
    {
        if((*(text + i) >= 'a' && *(text + i) <= 'z') || (*(text + i) >= 'A' && *(text + i) <= 'Z'))
        {
            pointer = 1;
        }
        i++;
    }
    if(pointer == 0)
    {
        printf("\nwohs ot gnihtoN\n");
        return 0;
    }

    /*if(reverse(text) != NULL)
    {
        printf("\n%s\n",text);
    }
    else
    {
        printf("\nError!\n");
    }

    if(remove_non_letters(text) != NULL)
    {
        printf("\n%s\n",text);
    }
    else
    {
        printf("\nError!\n");
    }*/

    if(trim(text) != NULL)
    {
        printf("\n%s",text);
    }
    else
    {
        printf("\nError!\n");
    }

    return 0;
}
