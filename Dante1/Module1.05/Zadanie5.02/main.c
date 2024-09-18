#include <stdio.h>

int main()
{
    char tekst[] = {'T','o',' ','j','e','s','t',' ','t','e','k','s','t','\x0'};

    for (int i = 0; tekst[i] != '\0'; i++)
    {
        char letter = tekst[i];
        int number = (int)letter;

        putc(letter, stdout);
        printf(" %i %c\n", number, letter);

    }

    return 0;
}
