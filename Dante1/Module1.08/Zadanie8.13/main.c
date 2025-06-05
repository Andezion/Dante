#include <stdio.h>

int sum_of_digits(long long number);
int is_divisible_by_3(int number);

int main()
{
    int number;

    printf("Enter: ");

    int check = scanf("%i", &number);
    if (check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int result = is_divisible_by_3(number);
    if (result == 1)
    {
        printf("\nYES");
    }
    if (result == 0)
    {
        printf("\nNO");
    }

    return 0;
}

int is_divisible_by_3(int number)
{
    int sum = sum_of_digits(number);
    if(sum == 0)
    {
        return 1;
    }
    if (sum < 3)
    {
        return 0;
    }

    return is_divisible_by_3(sum - 3);
}

int sum_of_digits(long long number)
{
    long long new;
    if(number > 0)
    {
        new = number;
    }
    else if(number < 0)
    {
        new = -1 * number;
    }
    if(number == 0)
    {
        return 0;
    }
    return (int)(new % 10) + sum_of_digits(new / 10);
}
