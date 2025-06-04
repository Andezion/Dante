#include <stdio.h>
#include <math.h>

int add(int, int);

int main()
{
    int num1, num2;

    printf("Enter num1: ");

    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Enter num2: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }

    printf("%i",add(num1, num2));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
