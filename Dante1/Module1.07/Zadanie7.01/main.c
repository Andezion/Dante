#include <stdio.h>
#include <math.h>

int test1(int a);

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


    printf("Result is: %i", test1(number));
    return 0;
}

int test1(int a)
{
    return a;
}
