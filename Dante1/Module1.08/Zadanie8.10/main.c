#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    long long number;

    printf("Enter number: ");
    int check = scanf("%lli",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int result = sum_of_digits(number);
    printf("\nResult: %i",result);

    return 0;
}

