#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input_text[101];
    char reversed_text[101];
    char final_text[1000];

    printf("Enter your text: ");
    scanf("%300s",input_text);

    size_t our_input_text_size = strlen(input_text);
    //printf("\n%i\n",(int)our_input_text_size);

    if(strlen(input_text) > 100)
    {
        printf("Input is too long");
        return 2;
    }

    int i;
    for(i = 0; i < (int)our_input_text_size; i++)
    {
        reversed_text[i] = input_text[our_input_text_size - i - 1];
    }
    reversed_text[i] = '\0';

    //printf("\n%s", input_text);
    //printf("\n%s", reversed_text);

    for(i = 0; i < (int)our_input_text_size; i++)
    {
        if(!isalpha(reversed_text[i]))
        {
            printf("Incorrect input");
            return 1;
        }
    }

    int j = 0;
    for(i = 0; i < (int)our_input_text_size; i++)
    {
        int number = 0;
        if(islower(reversed_text[i]))
        {
            final_text[j] = reversed_text[i];
            j++;
        }
        else if(isupper(reversed_text[i]))
        {
            while(number != 3)
            {
                final_text[j] = reversed_text[i];
                number++;
                j++;
            }
        }
    }
    final_text[j] = '\0';

    if(j > 200)
    {
        printf("Output is too long");
        return 3;
    }

    printf("\n%s",final_text);

    return 0;
}
