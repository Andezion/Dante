#include <stdio.h>
#include <string.h>
#include <ctype.h>

int helper(const char *word)
{
    for (int i = 1; word[i]; i++)
    {
        if (strchr("aeiouy", tolower(word[i])) && strchr("aeiouy", tolower(word[i - 1])))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char data[1001];
    int result = 0;

    printf("Enter: ");
    scanf("%1000[^\n]", data);

    char *word = strtok(data, " .,;:!?");
    while (word != NULL)
    {
        result = result + helper(word);
        word = strtok(NULL, " .,;:!?");
    }

    printf("\n%i\n", result);
    return 0;
}
