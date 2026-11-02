#include <stdio.h>

int main()
{
    float x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;

    printf("Enter numbers:");
    if (scanf("%f %f %f %f %f %f %f %f %f %f",&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9,&x10) != 10)
    {
        return 1;
    }

    printf("Result is = %.4f",(x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10) / 10);
    return 0;
}
