#include <stdio.h>

int main(void)
{
    for (int i = 65; i <= 90; i++)
    {
        printf("%d %c %c\n", i, i, i + 32);
    }

    return 0;
}
