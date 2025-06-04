#include <stdio.h>
#include <math.h>

int sqr(int a);

int main()
{
    int number;

    printf("Enter radix: ");
    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    int result = sqr(number);
    if(result == -1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Result is: %i",result);
    return 0;
}

int sqr(int a)
{
    return a * a;
}
