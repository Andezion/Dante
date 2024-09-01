#include <stdio.h>

int main()
{
    int number;
    printf("Enter number: ");
    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if(number < 0 || number > 10)
    {
        printf("Incorrect input data");
        return 2;
    }
    else if(number == 0)
    {
        printf("zero");
    }
    else if(number == 1)
    {
        printf("jeden");
    }
    else if(number == 2)
    {
        printf("dwa");
    }
    else if(number == 3)
    {
        printf("trzy");
    }
    else if(number == 4)
    {
        printf("cztery");
    }
    else if(number == 5)
    {
        printf("piec");
    }
    else if(number == 6)
    {
        printf("szesc");
    }
    else if(number == 7)
    {
        printf("siedem");
    }
    else if(number == 8)
    {
        printf("osiem");
    }
    else if(number == 9)
    {
        printf("dziewiec");
    }
    else if(number == 10)
    {
        printf("dziesiec");
    }
    return 0;
}
