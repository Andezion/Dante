#include <stdio.h>

int main()
{
    float num;
    printf("Enter number:");

    if (scanf("%f",&num) != 1)
    {
        return 1;
    }

    printf("Result is = %f",2 * num * num * num - 4 * num * num + 3 * num - 7);
    return 0;
}
