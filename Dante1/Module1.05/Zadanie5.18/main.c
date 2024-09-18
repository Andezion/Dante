#include <stdio.h>
#include <string.h>

int main()
{
    char input_text[51];
    int token = 0;

    printf("Enter: ");
    scanf("%50s", input_text);

    for (size_t i = 0; i < strlen(input_text); i++)
    {
        if (input_text[i] == '(')
        {
            token++;
        }
        else if (input_text[i] == ')')
        {
            token--;
        }

        if (token < 0)
        {
            printf("\nNiepoprawny");
            return 0;
        }
    }

    if (token == 0)
    {
        printf("\nPoprawny");
    }
    else
    {
        printf("\nNiepoprawny");
    }

    return 0;
}
