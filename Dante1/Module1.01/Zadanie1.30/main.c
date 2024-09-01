#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    printf("Input time: ");
    scanf("%i",&a);
    int x = a/3600;
    a = a - x*3600;
    int y = a/60;
    a = a - y*60;
    int z = a;
    printf("%.2i:%.2i:%.2i",x,y,z);
    return 0;
}
