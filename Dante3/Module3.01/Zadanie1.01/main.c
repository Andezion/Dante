#include <stdio.h>

int sum_short_int_int(const void * const in1, const void * const in2, void *out);

int main()
{
    short in1 = 5;
    int in2 = 6;
    int out = 0;
    printf("%i ", sum_short_int_int((const void *) &in1, (const void *) &in2, (void *) &out));
    return 0;
}

int sum_short_int_int(const void * const in1, const void * const in2, void *out)
{
    if(in1 == NULL || in2 == NULL || out == NULL)
    {
        return 1;
    }

    *(int *) out = 0;
    *(int *)out = *(short *)in1 + *(int *)in2;

    return 0;
}
