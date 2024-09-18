#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input_text[100];
    char reversed_text[100];
    char final_text[1000];

    printf("Enter your text: ");
    scanf("%99[^\n]s", input_text);

    if(strlen(input_text) >= 99)
    {
        printf("Input is too long");
        return 2;
    }

    size_t our_input_text_size = strlen(input_text);

    int i;
    for(i = 0; i < (int)our_input_text_size; i++)
    {
        reversed_text[i] = input_text[our_input_text_size - i - 1];
    }
    reversed_text[i] = '\0';

    if(isdigit(reversed_text[0]))
    {
        printf("Incorrect input");
        return 1;
    }

    for(i = 0; i < (int)our_input_text_size; i++)
    {
        if(isdigit(reversed_text[i]) && isdigit(reversed_text[i + 1]))
        {
            printf("Incorrect input");
            return 1;
        }
    }

    int j = 0;
    for(i = 0; i < (int)our_input_text_size; i++)
    {
        int number = 1;
        if(!isdigit(reversed_text[i]))
        {
            final_text[j] = reversed_text[i];
            j++;
        }
        else
        {
            while(number != reversed_text[i] - 48)
            {
                final_text[j] = reversed_text[i - 1];
                number++;
                j++;
            }
        }
    }
    final_text[j] = '\0';

    //printf("\n%i", (int)strlen(final_text));
    if(j > 200)
    {
        printf("Output is too long");
        return 3;
    }

    printf("\n%s",final_text);

    return 0;
}
