#include <stdio.h>

int compare(int, int, int);

int main()
{
    int num1, num2, num3;

    printf("Enter numbers: ");

    int check = scanf("%i-%i-%i",&num1,&num2,&num3);
    if(check != 3)
    {
        printf("Incorrect input\n");
        return 1;
    }

    if(compare(num1, num2, num3) == 1)
    {
        printf("EQUAL");
    }
    else
    {
        printf("NOT EQUAL");
    }

    return 0;
}

int compare(int a, int b, int c)
{
    if(a == b && b == c)
    {
        return 1;
    }
    return 0;
}
