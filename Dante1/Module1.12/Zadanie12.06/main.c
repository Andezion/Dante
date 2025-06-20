#include <stdio.h>

int is_balanced(unsigned long long a)
{
    int num1 = 0, num2 = 0;
    for(size_t i = 1; i <= a; i++)
    {
        if(a % i == 0)
        {
            if(i % 2 == 0)
            {
                num1++;
            }
            if(i % 2 == 1)
            {
                num2++;
            }
        }
    }

    if(num1 == num2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    unsigned long int number;

    printf("Enter: ");

    int check = scanf("%lu",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }


    while(1)
    {
        number++;
        if(is_balanced(number) == 1)
        {
            break;
        }
    }

    printf("\n%lu",number);

    return 0;
}
