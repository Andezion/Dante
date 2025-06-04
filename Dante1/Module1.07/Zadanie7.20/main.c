#include <stdio.h>

int clamp(int x, int lo, int hi);

int main()
{
    int x, lo, hi;

    printf("Enter x: ");
    int check1 = scanf("%i",&x);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter lo: ");
    int check2 = scanf("%i",&lo);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter hi: ");
    int check3 = scanf("%i",&hi);
    if(check3 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int result = clamp(x, lo, hi);
    printf("%i",result);

    return 0;
}

int clamp(int x, int lo, int hi)
{
    if(lo > hi)
    {
        int temp = lo;
        lo = hi;
        hi = temp;
    }
    if(x > lo && x < hi)
    {
        return x;
    }
    else if(x <= lo)
    {
        return lo;
    }
    else
    {
        return hi;
    }
}
