#include <stdio.h>

int main()
{
    unsigned long long int result = 1;
    int i;

    for (i = 0; i <= 19; i++)
        printf("%llu ", result), result *= 10;

    return 0;
}
