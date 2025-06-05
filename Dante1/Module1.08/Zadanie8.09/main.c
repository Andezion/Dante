#include <stdio.h>

long long binary_exponentiation(long long a, unsigned int n)
{
    if(n == 0)
    {
        return 1;
    }

    long long half_result = binary_exponentiation(a, n / 2);

    if(n % 2 == 0)
    {
        return half_result * half_result;
    }
    else
    {
        return a * half_result * half_result;
    }
}

int main()
{
    long long a;

    printf("Enter number: ");

    int check1 = scanf("%lli",&a);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    unsigned int n;

    printf("\nEnter n: ");
    int check2 = scanf("%u",&n);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    long long result = binary_exponentiation(a, n);
    printf("\nResult is: %lli",result);

    return 0;
}
