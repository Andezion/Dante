#include <stdio.h>

int main()
{
    unsigned long long num;

    printf("Enter: ");

    if (scanf("%llu",&num) != 1) {
        printf("Incorrect input");
        return 1;
    }

    unsigned long long temp = num;

    while(num > 9)
    {
        num = num / 10;
    }

    printf("%llu\n%llu",num, temp % 10);

    return 0;
}
