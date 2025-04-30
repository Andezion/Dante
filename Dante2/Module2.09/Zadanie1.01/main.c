#include <stdio.h>

int is_equal(int a, int b)
{
    if(a ^ b)
    {
        return 0;
    }
    return 1;
}

int is_negative(int value)
{
    int res = (value >> 31) & 1;
    return res;
}

int main()
{
    int a, b;
    int error;

    printf("Enter a and b: ");
    error = scanf("%i %i", &a, &b);
    if(!is_equal(error, 2))
    {
        printf("Incorrect input");
        return 1;
    }

    error = is_equal(a, b);
    if (!is_equal(error, 0))
    {
        printf("rowne\n");
    }
    else
    {
        printf("nierowne\n");
    }

    if (is_negative(a))
    {
        printf("ujemna ");
    }
    else
    {
        printf("nieujemna ");
    }

    if (is_negative(b))
    {
        printf("ujemna");
    }
    else
    {
        printf("nieujemna");
    }

    return 0;
}
