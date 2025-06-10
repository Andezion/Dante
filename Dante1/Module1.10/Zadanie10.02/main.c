#include <stdio.h>

int main()
{
    int a = 1;
    int *b = &a;

    printf("%d %d %p\n", a, *b, (void *)b);

    *b = 5;

    printf("%d %d %p\n", a, *b, (void *)b);

    return 0;
}
