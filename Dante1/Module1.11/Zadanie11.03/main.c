#include <stdio.h>
#include <string.h>
#include <ctype.h>

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace);

int main()
{
    char text[1001];
    printf("Enter: ");

    scanf("%1000[^\n]",text);

    int uppercase = 0, lowercase = 0, whitespace = 0;
    int check = marks_counter(text, &uppercase, &lowercase, &whitespace);
    if (check == 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("\n%i\n%i\n%i\n",uppercase,lowercase,whitespace);

    return 0;
}

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace)
{
    if (text == NULL || uppercase == NULL || lowercase == NULL || whitespace == NULL)
    {
        return 1;
    }

    int uppercase_counter = 0;
    int lowercase_counter = 0;
    int whitespace_counter = 0;

    for (size_t i = 0; i < strlen(text); i++)
    {
        if (islower((unsigned char)*(text + i)))
        {
            lowercase_counter++;
        }
        else if (*(text+i) == '\t' || *(text+i) == ' ' || *(text+i) == '\n')
        {
            whitespace_counter++;
        }
        else if (isupper((unsigned char)*(text + i)))
        {
            uppercase_counter++;
        }
        /*else if (isspace((unsigned char)*(text + i)))
        {
            whitespace_counter++;
        }*/
        else
        {

        }
    }

    *uppercase = uppercase_counter;
    *lowercase = lowercase_counter;
    *whitespace = whitespace_counter;

    return 0;
}
