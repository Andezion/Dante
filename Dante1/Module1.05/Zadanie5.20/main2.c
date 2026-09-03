#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

char *cesar(const char *text, const size_t size, int n)
{
    char *result = calloc(size + 1, sizeof(char));
    if (result == NULL)
    {
        return NULL;
    }

    n = (n % 26 + 26) % 26;

    for (size_t i = 0; i < size; i++)
    {
        const char c = text[i];

        if (isupper((unsigned char)c))
        {
            result[i] = (char) ('A' + (c - 'A' + n) % 26);
        }
        else if (islower((unsigned char)c))
        {
            result[i] = (char) ('a' + (c - 'a' + n) % 26);
        }
        else
        {
            result[i] = c;
        }
    }

    return result;
}

int main(void)
{
    char text[1000];
    printf("Enter: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        return 1;
    }

    text[strcspn(text, "\n")] = '\0';

    int number;
    printf("Enter number:\n");
    if (scanf("%d", &number) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    size_t actual_size = strlen(text);
    char *result = cesar(text, actual_size, number);
    if (result == NULL)
    {
        printf("Buy new computer");
        return 2;
    }

    printf("%s\n", result);
    free(result);
    return 0;
}
