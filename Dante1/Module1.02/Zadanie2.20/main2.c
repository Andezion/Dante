#include <stdio.h>
#include <string.h>

int is_special(char c)
{
    return c != '\0' && strchr("xyz27", c) != NULL;
}

int main(void)
{
    char p1, p2, p3, p4, p5;

    printf("Enter smth: ");

    if (scanf("%c%c%c%c%c", &p1, &p2, &p3, &p4, &p5) != 5)
    {
        printf("Error");
        return 0;
    }

    printf("%d", is_special(p1) + is_special(p2) + is_special(p3)
               + is_special(p4) + is_special(p5));

    return 0;
}
