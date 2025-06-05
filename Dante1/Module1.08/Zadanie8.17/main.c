#include <stdio.h>
#include <stdlib.h>

int is_divisible_by_7(int number);

int main()
{
    int number;

    printf("Enter: ");
    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int result = is_divisible_by_7(number);
    if(result == 1)
    {
        printf("\nYES");
    }
    if(result == 0)
    {
        printf("\nNO");
    }

    return 0;
}

int is_divisible_by_7(int number)
{
    int new = abs(number);
    if(new == 0)
    {
        return 1;
    }
    if(new < 7)
    {
        return 0;
    }

    return is_divisible_by_7(new - 7);
}
