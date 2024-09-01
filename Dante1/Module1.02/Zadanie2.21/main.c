#include <stdio.h>

int main()
{
    int num1, num2;
    char type;

    printf("Enter: ");
    int check1 = scanf("%i",&num1);
    if(check1 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");
    int check2 = scanf("%i",&num2);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    getchar();

    printf("\nEnter: ");
    scanf("%c",&type);


    printf("\n");
    if(type == '-')
    {
        printf("%i",num1 - num2);
    }
    else if(type == '+')
    {
        printf("%i",num1 + num2);
    }
    else if(type == '*')
    {
        printf("%i",num1 * num2);
    }
    else if(type == '/')
    {
        if(num2 == 0)
        {
            printf("Operation not permitted");
            return 2;
        }
        printf("%.2f",(float)num1 / (float)num2);
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }
    
    return 0;
}
