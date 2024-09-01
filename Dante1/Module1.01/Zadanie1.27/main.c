#include <stdio.h>

int main()
{
    int num1, num2;
    char type;

    printf("Enter number: ");

    int num3 = scanf("%i%ci%i",&num1,&type,&num2);
    printf("%i%c%ii\n%i",num1,type,num2,num3);
    return 0;
}
