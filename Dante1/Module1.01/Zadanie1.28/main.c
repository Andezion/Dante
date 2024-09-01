#include <stdio.h>

int main()
{
    int x;
    int y;
    int z;
    printf("Podaj liczby: ");
    scanf("%i %i %i",&x,&y,&z);
    printf("%i",(x >= y) + (x >= z));
    return 0;
}
