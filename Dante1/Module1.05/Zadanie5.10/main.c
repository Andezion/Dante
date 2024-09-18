#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input_text[1001];
    printf("Enter text: ");

    scanf("%1000[^\n]s", input_text);

    for (size_t i = 0; i < strlen(input_text); i++)
    {
        if (!isalpha(input_text[i]) && input_text[i] != ' ')
        {
            printf("Incorrect input\n");
            return 1;
        }
    }

    int data_storage[100] = { 0 };

    int temp_number = 0;
    for(size_t i = 0; i < strlen(input_text); i++)
    {
        if(isalpha(input_text[i]))
        {
            temp_number++;
        }
        else
        {
            if (temp_number > 0)
            {
                data_storage[temp_number]++;
                temp_number = 0;
            }
        }
    }

    if (temp_number > 0)
    {
        data_storage[temp_number]++;
    }

    int max = 0;
    int counter = 0;
    for(int i = 0; i < 100; i++)
    {
        if(data_storage[i] != 0)
        {
            if(i > max)
            {
                max = i;
                counter = data_storage[i];
            }
        }
    }

    printf("\n%i %i", counter, max);

    int j = 0;
    int index_storage[1000] = { 0 };

    temp_number = 0;
    for(size_t i = 0; i < strlen(input_text); i++)
    {
        if(isalpha(input_text[i]))
        {
            temp_number++;
        }
        else
        {
            if (temp_number > 0)
            {
                if(temp_number == max)
                {
                    index_storage[j] = (int) i - max;
                    j++;
                }
                temp_number = 0;
            }
        }
    }

    if (temp_number == max)
    {
        index_storage[j] = (int) strlen(input_text) - max;
        j++;
    }

    printf("\n");
    for(int a = j - 1; a >= 0; a--)
    {
        for(int b = 0; b < max; b++)
        {
            printf("%c", input_text[index_storage[a] + b]);
        }
        printf("\n");
    }

    return 0;
}
