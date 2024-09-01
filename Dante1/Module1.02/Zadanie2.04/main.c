#include <stdlib.h>
#include <stdio.h>

int main()
{
    int num1,num2;
    char oper;

    printf("Enter something: ");
    int check = scanf("%d%ci%d",&num1,&oper,&num2);
    if(check != 3 || num2 < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    if(oper == '-')
    {
        printf("Real: %i\n",num1);
        printf("Image: %i\n",-1 * num2);
    }
    else if(oper == '+')
    {
        printf("Real: %i\n",num1);
        printf("Image: %i\n",num2);
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }
    return 0;
}
