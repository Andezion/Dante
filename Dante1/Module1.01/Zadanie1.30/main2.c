#include <stdio.h>

int main()
{
    int a;
    printf("Input time: ");
    scanf("%d", &a);

    int x = a / 3600;
    a = a - x * 3600;
    int y = a / 60;
    a = a - y * 60;
    int z = a;

    printf("%.2d:%.2d:%.2d", x, y, z);
    return 0;
}
