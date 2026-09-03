#include <stdio.h>

int main(void)
{
    char tekst[] = {'T','o',' ','j','e','s','t',' ','t','e','k','s','t','\x0'};
    for (int i = 0; tekst[i] != '\0'; i++)
    {
        putc(tekst[i], stdout);
        printf(" %i %c\n", (int) tekst[i], tekst[i]);

    }

    return 0;
}
