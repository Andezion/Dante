#include <stdio.h>

char* get_word(char* str)
{
    if (str == NULL)
    {
        return NULL;
    }

    while (*str && *str != ' ')
    {
        ++str;
    }
    while (*str && *str == ' ')
    {
        ++str;
    }

    if (*str)
    {
        return str;
    }
    else
    {
        return NULL;
    }
}


int main()
{
    char text[1001];
    printf("Enter: ");
    scanf("%1000[^\n]",text);

    char *p1 = text;
    char *p2;

    printf("\n");

    while (p2 = get_word(p1))
    {
        printf("%.*s\n", (int) (p2 - p1), p1);
        p1 = p2;
    }

    printf("%s\n", p1);

    return 0;
}
