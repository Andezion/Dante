#include <stdio.h>

int main()
{
    int x, y,z;
    printf("Podaj liczby: ");
    scanf("%d %d %d",&x,&y,&z);
    printf("%d",(x >= y) + (x >= z));
    return 0;
}
