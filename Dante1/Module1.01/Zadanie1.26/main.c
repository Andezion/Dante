#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, z;

    printf("Enter data: ");
    scanf("%d-%d-%d",&x,&y,&z);
    printf("Day:%6s%02d\nMonth:%4s%02d\nYear:%3s%04d", "",x, "",y, "",z);
    return 0;
}
