#include <stdio.h>

int main()
{
    int number;
    int counter = 0;

    printf("Enter number: ");

    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    for(int i = 1; i <= number; i++)
    {
        if(number % i == 0)
        {
            counter++;
        }
    }

    if(counter == 2)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
