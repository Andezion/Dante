#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[11];
    printf("Enter name: ");
    scanf("%10[^\n]", name);

    if (name[strlen(name) - 1] == 'a' && strcmp(name, "Kuba") != 0 && strcmp(name, "Bonawenturaa") != 0)
    {
        printf("Imie zenskie");
    }
    else
    {
        printf("Imie meskie");
    }

    return 0;
}
