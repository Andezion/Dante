#include <stdio.h>

int swap(int *a, int *b);
int clamp(int *v, int lo, int hi);

int main()
{
    int v, lo, hi;

    printf("Enter v: ");
    int check1 = scanf("%i",&v);
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

    if(hi < lo)
    {
        swap(&hi,&lo);
    }

    clamp(&v, lo, hi);


    printf("%i",v);

    return 0;
}

int clamp(int *v, int lo, int hi)
{
    if (v == NULL || hi < lo)
    {
        return 1;
    }

    if (*v < lo)
    {
        *v = lo;
        swap(v, &lo);
    }
    else if (*v > hi)
    {
        *v = hi;
        swap(v, &hi);
    }

    return 0;
}

int swap(int *a, int *b)
{
    if(a == NULL || b == NULL || a == b)
    {
        return 1;
    }

    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

