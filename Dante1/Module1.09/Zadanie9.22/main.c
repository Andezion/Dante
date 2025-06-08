#include <stdio.h>
#include <string.h>

int sort_lowercase(char tab[])
{
    if(tab == NULL)
    {
        return 1;
    }

    for(size_t i = 0; i < strlen(tab); i++)
    {
        if(!('a' <= tab[i] && tab[i] <= 'z'))
        {
            return 1;
        }
    }

    for(size_t i = 0; i < strlen(tab) - 1; i++)
    {
        for(size_t j = i + 1; j < strlen(tab); j++)
        {
            if(tab[i] > tab[j])
            {
                char temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    return 0;
}

int main()
{
    char tab[31];

    printf("Enter: ");
    scanf("%30s",tab);

    int result = sort_lowercase(tab);
    if(result == 1)
    {
        printf("\nincorrect input data\n");
        return 2;
    }

    printf("\n%s\n",tab);

    return 0;
}
