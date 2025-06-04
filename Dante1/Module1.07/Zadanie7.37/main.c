#include <stdio.h>
#include <ctype.h>

int custom(const char tab[])
{
    int i = 0;

    while(tab[i] != '\0')
    {
        i++;
    }

    return i;
}

int find_string(const char tab[], const char tab2[]);
int rfind_string(const char tab[], const char tab2[]);

int main()
{
    char input_main[1001];
    printf("Enter: ");
    scanf("%1000[^\n]s", input_main);

    while (getchar() != '\n');

    char input_find[1001];
    printf("\nEnter: ");
    scanf("%1000[^\n]s", input_find);

    printf("\n%i\n%i", find_string(input_main, input_find), rfind_string(input_main, input_find));

    return 0;
}

int find_string(const char tab[], const char tab2[])
{
    if (tab == NULL || tab2 == NULL) {
        return -1;
    }

    int size = custom(tab);
    int size2 = custom(tab2);

    if (size2 == 0 || size == 0)
    {
        return -1;
    }

    for (int i = 0; i <= size - size2; i++)
    {
        int j;
        for (j = 0; j < size2; j++)
        {
            if (tab[i + j] != tab2[j])
            {
                break;
            }
        }
        if (j == size2)
        {
            return i;
        }
    }

    return -1;
}

int rfind_string(const char tab[], const char tab2[])
{
    if (tab == NULL || tab2 == NULL)
    {
        return -1;
    }

    int size = custom(tab);
    int size2 = custom(tab2);

    if (size2 == 0 || size2 > size)
    {
        return -1;
    }

    for (int i = size - size2; i >= 0; i--)
    {
        int j = 0;
        for (; j < size2; j++)
        {
            if (tab[i + j] != tab2[j])
            {
                break;
            }
        }
        if (j == size2)
        {
            return i;
        }
    }

    return -1;
}
