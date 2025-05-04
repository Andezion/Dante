#include <stdio.h>
#include <stdint.h>

int main()
{
    int error;
    uint64_t num;

    printf("Enter number: ");
    error = scanf("%lu", &num);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");
    for (int i = 63; i >= 0; --i)
    {
        printf("%lu", (num >> i) & 1);
        if (i % 8 == 0)
        {
            printf(" ");
        }
    }

    return 0;
}
