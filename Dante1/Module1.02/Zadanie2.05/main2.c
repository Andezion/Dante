#include <stdio.h>

int main()
{
    int number;
    printf("Enter number: ");

    if (scanf("%i",&number) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    (!number) ? printf("Equal to zero") : printf("Not equal to zero");

    return 0;
}
