#include <stdio.h>
#include <string.h>

char letters[] = "aAiIeEuUyYoO";

void removeChar(char *str, const char garbage) {

    char *dst;
    for (const char *src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage)
        {
            dst++;
        }
    }
    *dst = '\0';
}

int main(void)
{
    char text[1000];
    printf("Enter text: ");
    scanf("%999[^\n]", text);

    int counter = 0;
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (strchr(letters, text[i]) != NULL)
        {
            removeChar(letters, text[i]);
            counter++;
        }
    }

    printf("Result: %d\n", counter);

    return 0;
}
