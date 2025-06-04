#include <stdio.h>

size_t my_strlen(char tab[])
{
    size_t size = 0;
    while(*(tab + size) != '\0')
    {
        size++;
    }
    return size;
}

void replace(char tab[], char from, char to)
{
    if(tab == NULL)
    {
        return;
    }
    for(size_t i = 0; i < my_strlen(tab); i++)
    {
        if(tab[i] == from)
        {
            tab[i] = to;
        }
    }
}

void replace_string(char tab[], const char from[], const char to[])
{
    if(tab == NULL || from == NULL || to == NULL)
    {
        return;
    }

    int size = 0;
    int new_size = 0;

    while (from[size] != '\0')
    {
        ++size;
    }
    while (to[new_size] != '\0')
    {
        ++new_size;
    }

    int i;
    for (i = 0; tab[i] != '\0'; i++)
    {
        int j;
        for (j = 0; j < size && tab[i + j] == from[j]; j++)
        {

        }
        if (j != size)
        {
            continue;
        }
        int i1;
        for (i1 = i; i1 < i + new_size; i1++)
        {
            tab[i1] = to[i1 - i];
        }
        for (i1 = i + new_size; tab[i1] != '\0'; i1++)
        {
            tab[i1 + size - new_size] = tab[i1];
        }
        *(tab + i1) = '\0';
    }

}

int main()
{
    char tab[1001];
    printf("Enter: ");
    scanf("%1000[^\n]",tab);

    char helper[1001];
    int i;
    for(i = 0; *(tab + i) != '\0'; i++)
    {
        helper[i] = tab[i];
    }
    *(helper + i) = '\0';

    printf("\n%s\n",helper);

    replace(tab,'t','s');
    printf("\n%s",tab);

    replace_string(helper,"jest","test");
    printf("\n%s\n",helper);

    return 0;
}
