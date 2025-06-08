#include <string.h>
#include <stdio.h>
#include <malloc.h>

int sort_digits(char tab[])
{
    if(tab == NULL)
    {
        return 1;
    }

    int size = (int)strlen(tab);
    for(int i = 0; i < size; i++)
    {
        if(!(tab[i] >= '0' && tab[i] <= '9'))
        {
            return 1;
        }
    }

    int counter = 0;
    for(int i = 0; i < size; i++)
    {
        if(tab[i] != '0')
        {
            counter++;
        }
    }

    char *new_tab = malloc(sizeof(char) * (counter + 1));
    if(new_tab == NULL)
    {
        return 1;
    }
    *(new_tab + counter) = '\0';

    int j1 = 0;
    for(int i = 0; i < size; i++)
    {
        if(tab[i] != '0')
        {
            new_tab[j1] = tab[i];
            j1++;
        }
    }

    for(int i = 0; i < counter - 1; i++)
    {
        for(int j = i + 1; j < counter; j++)
        {
            if(new_tab[i] > new_tab[j])
            {
                char temp = new_tab[i];
                new_tab[i] = new_tab[j];
                new_tab[j] = temp;
            }
        }
    }

    strcpy(tab,new_tab);

    free(new_tab);
    return 0;
}

int main()
{
    char tab[501];

    printf("Enter: ");
    scanf("%500s",tab);

    int result = sort_digits(tab);
    if(result == 1)
    {
        printf("\nIncorrect input data\n");
        return 2;
    }

    int point = 0;
    for(size_t i = 0; i < strlen(tab); i++)
    {
        if(tab[i] >= '1' && tab[i] <= '9')
        {
            point = 1;
        }
    }
    if(point == 0)
    {
        printf("\nNothing to show\n");
        return 0;
    }

    printf("\n%s\n",tab);
    return 0;
}
