#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input_text[1001];
    printf("Enter text: ");

    scanf("%1000[^\n]s", input_text);

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

    int counter = 0;
    for(int i = 0; i < 100; i++)
    {
        if(data_storage[i] != 0)
        {
            counter += data_storage[i];
        }
    }

    printf("\n%i",counter);

    return 0;
}
