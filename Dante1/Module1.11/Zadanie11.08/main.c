#include <stdio.h>

char* change_letter_size(char* dest, const char* src)
{
    if (src == NULL || dest == NULL)
    {
        return NULL;
    }

    int i = 0;
    while (*(src + i) != '\0')
    {
        if (*(src + i) >= 'a' && *(src + i) <= 'z')
        {
            *(dest + i) = *(src + i) - 32;
        }
        else if (*(src + i) >= 'A' && *(src + i) <= 'Z')
        {
            *(dest + i) = *(src + i) + 32;
        }
        else
        {
            *(dest + i) = *(src + i);
        }
        i++;
    }
    *(dest + i) = '\0';

    return dest;
}

int main()
{
    char src[1001];
    char dest[1001];

    printf("Enter: ");
    scanf("%1000[^\n]", src);

    char *check = change_letter_size(dest, src);
    if(check == NULL)
    {
        printf("\nIncorrect input");
        return 1;
    }

    printf("\n%s", dest);

    return 0;
}
