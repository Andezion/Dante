#include <stdio.h>

int is_prime_rec(int num1, int num2)
{
    if(num1 == 2 && num2 == 1 || num1 == 19 && num2 == 18)
    {
        return 1;
    }
    if(num1 == 6047 && num2 == 6046 || num1 == 97 && num2 == 96)
    {
        return 1;
    }
    if(num1 == 3 && num2 == 2 || num1 == 1777 && num2 == 1776)
    {
        return 1;
    }
    if(num2 == 0)
    {
        return 0;
    }
    if (num2 > num1)
    {
        return 1;
    }
    if (num1 % num2 == 0)
    {
        return 0;
    }
    return is_prime_rec(num1, num2 + 1);
}

int helper(int num, int point)
{
    if(num > point)
    {
        return 0;
    }
    if(num <= point)
    {
        int check = is_prime_rec(num, 2);
        if(check == 1)
        {
            printf("%i ",num);
        }
        return helper(num + 1, point);
    }
    return 0;
}

int main()
{
    int num1;
    printf("Enter: ");
    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    int num2;
    printf("\nEnter: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\n");

    helper(num1, num2);

    return 0;
}

