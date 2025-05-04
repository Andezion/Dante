#include <stdio.h>
#include <stdint.h>

int main()
{
    int error;
    int64_t num;
    printf("Enter: ");

    error = scanf("%ld", &num);
    if (error != 1)
    {
        printf("\nInput error");
        return ~1 + 1;
    }

    int64_t res = ~num + 1;
    printf("\n%ld", res);

    return 0;
}
