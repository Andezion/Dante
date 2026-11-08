#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char l1, l2, l3, l4, l5;

    printf("Enter: ");

    if (scanf("%c%c%c%c%c", &l1, &l2, &l3, &l4, &l5) != 5)
    {
        printf("Error");
        return 0;
    }

    printf("\n%c%c%c%c%c", toupper(l1), toupper(l2), toupper(l3), toupper(l4), toupper(l5));

    return 0;
}
