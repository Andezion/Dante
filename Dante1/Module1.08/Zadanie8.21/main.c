#include <stdio.h>

int digits_in_number(unsigned long long number, unsigned int digit)
{
    if (number == 0)
    {
        if (digit == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    unsigned int temp = number % 10;

    int counter;
    if (temp == digit)
    {
        counter = 1;
    }
    else
    {
        counter = 0;
    }

    if (digit == 0 && temp == 0)
    {
        counter--;
    }

    return counter + digits_in_number(number / 10, digit);
}

int main()
{
    unsigned long long number;

    printf("Enter number: ");
    int check1 = scanf("%llu",&number);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    unsigned int digit;

    printf("\nEnter digit: ");
    int check2 = scanf("%u",&digit);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(digit > 10)
    {
        printf("Incorrect input data");
        return 2;
    }

    int result = digits_in_number(number,digit);
    printf("\nResult is: %i",result);

    return 0;
}
