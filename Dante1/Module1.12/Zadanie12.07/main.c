#include <stdio.h>
#include <math.h>

int helper(double n)
{
    double counter = 0;
    double index = 0;

    for(int i = 1; i < n; i++)
    {
        if((int)n % i == 0)
        {
            counter = counter + i;
            index++;
        }
    }

    double result = counter / index;
    if(result <= sqrt(n))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int num1, num2;

    printf("Enter: ");
    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(num2 < num1)
    {
        printf("Incorrect input data");
        return 2;
    }

    int counter = 0;
    for(int i = num1; i <= num2; i++)
    {
        if(helper(i) == 1)
        {
            counter++;
        }
    }

    printf("\n%i",counter);

    return 0;
}
