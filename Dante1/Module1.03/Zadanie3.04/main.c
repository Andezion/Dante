#include <stdio.h>

int main()
{
    unsigned long long num;

    printf("Enter: ");

    int check = scanf("%llu",&num);
    if(check != 1)
    {
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
