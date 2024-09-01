#include <stdio.h>

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

    printf("\n");

    if(number >= 0 && number <= 10)
    {
        printf("ocena 2");
    }
    else if(number >= 11 && number <= 13)
    {
        printf("ocena 3");
    }
    else if(number >= 14 && number <= 16)
    {
        printf("ocena 4");
    }
    else if(number >= 17 && number <= 20)
    {
        printf("ocena 5");
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    return 0;
}
