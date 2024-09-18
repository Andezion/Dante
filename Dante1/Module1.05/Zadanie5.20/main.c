#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[1000];
    printf("Enteeeeeer: ");
    scanf("%999[^\n]",input);

    int type;
    printf("I want to kill myself: ");
    int check = scanf("%i",&type);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int i = 0;
    while (input[i] != '\0')
    {
        if (!isalpha(input[i]))
        {
            
        }
        else
        {
            char base;
            if (!islower(input[i]))
            {
                base = 'A';
            }
            else
            {
                base = 'a';
            }
            input[i] = (char) ((input[i] - base + type) % 26 + base);
        }
        i++;
    }

    printf("%s",input);

    return 0;
}
