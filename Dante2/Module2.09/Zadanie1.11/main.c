#include <stdio.h>

unsigned long long add(unsigned long long a, unsigned long long b);

int main()
{
    int error;
    unsigned long long a, b;

    printf("Enter numbers: ");
    error = scanf("%llu", &a);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    error = scanf("%llu", &b);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    unsigned long long result = add(a, b);
    printf("%llu", result);

    return 0;
}

unsigned long long add(unsigned long long a, unsigned long long b)
{
    unsigned long long dupochka;

    while (b != 0)
    {
        dupochka = a & b;
        a = a ^ b;
        b = dupochka << 1;
    }

    return a;
}
