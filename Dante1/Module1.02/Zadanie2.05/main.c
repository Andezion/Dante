#include <stdio.h>

int main()
{
    int number;
    printf("Enter number: ");

    int check = scanf("%i",&number);
    if(!check)
    {
        printf("Incorrect input");
        return 1;
    }

    if(!number)
    {
        printf("Equal to zero");
    }
    else
    {
        printf("Not equal to zero");
    }
    return 0;
}
