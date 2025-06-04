#include <stdio.h>

int custom(const char tab[])
{
    int i = 0;

    while(tab[i] != '\0')
    {
        i++;
    }

    return i;
}

int find_char(const char tab[], char c);
int rfind_char(const char tab[], char c);

int main()
{
    char input_text[1001];
    printf("Enter: ");
    scanf("%1000[^\n]s", input_text);

    while(getchar() != '\n');

    char letter;
    printf("\nEnter letter: ");
    scanf("%c", &letter);

    printf("\n%i\n%i", find_char(input_text, letter), rfind_char(input_text, letter));

    return 0;
}

int rfind_char(const char tab[], char c)
{
    if(tab == NULL)
    {
        return -1;
    }

    int size = custom(tab);
    for(int i = size - 1; i >= 0; i--)
    {
        if(tab[i] == c)
        {
            return i;
        }
    }

    return -1;
}

int find_char(const char tab[], char c)
{
    if(tab == NULL)
    {
        return -1;
    }

    int size = custom(tab);
    for(int i = 0; i < size; i++)
    {
        if(tab[i] == c)
        {
            return i;
        }
    }

    return -1;
}
