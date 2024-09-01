#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2;
    printf("Enter numbers: ");

    int check = scanf("%i %i",&num1,&num2);
    if(check != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%i",num1 + num2);
    return 0;
}
