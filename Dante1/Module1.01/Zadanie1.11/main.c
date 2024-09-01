
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

    printf("%i\n%i",number, number * 10);
    return 0;
}
