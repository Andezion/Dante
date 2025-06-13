#include <stdio.h>

char* space_changer(char *txt)
{
    if(txt == NULL)
    {
        return NULL;
    }

    for(int i = 0; *(txt + i) != '\0'; i++)
    {
        if(*(txt + i) == ' ')
        {
            *(txt + i) = '_';
        }
    }

    return txt;
}

int main()
{
    char txt[1001];
    printf("Enter: ");
    scanf("%1000[^\n]",txt);

    char *result = space_changer(txt);
    if(result == NULL)
    {
        printf("Error!");
        return 1;
    }

    printf("\n%s\n",txt);

    return 0;
}
