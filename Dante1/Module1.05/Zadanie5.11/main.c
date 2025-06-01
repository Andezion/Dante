#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input_text[1000];

    printf("Enter: ");
    scanf("%1000[^\n]s", input_text);

    for(size_t i = 0; i < strlen(input_text); i++)
    {
        if(!isdigit(input_text[i]) && input_text[i] != '|' && input_text[i] != '-')
        {
            printf("Incorrect input");
            return 1;
        }
    }

    long result[100];
    int result_index = 0;
    long sum = 0;

    int inside_segment = 0;
    long current_number = 0;
    int number_exists = 0;

    for(size_t i = 0; i <= strlen(input_text); i++)
    {
        char current = input_text[i];

        if (current == '|' || current == '\0')
        {
            if (inside_segment)
            {
                sum += current_number;
                result[result_index++] = sum;
                sum = 0;
                current_number = 0;
            }
            else
            {
                result[result_index++] = 0;
            }
            inside_segment = 1;
            number_exists = 0;
        }
        else if (isdigit(current))
        {
            current_number = current_number * 10 + (current - '0');
            number_exists = 1;
        }
        else if (current == '-')
        {
            if (number_exists)
            {
                sum = sum + current_number;
                current_number = 0;
                number_exists = 0;
            }
        }
    }

    for(int i = 0; i < result_index; i++)
    {
        printf("%ld ", result[i]);
    }

    return 0;
}
