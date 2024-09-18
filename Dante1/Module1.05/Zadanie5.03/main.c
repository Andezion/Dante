#include <stdio.h>

int main()
{
    char data[31];

    printf("Enter smth: ");
    scanf("%30s",data);

    printf("Witaj %s!",data);

    return 0;
}
