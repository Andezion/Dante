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

    int num = 1;
    int result = 0;
    while(1)
    {
        if(number % num == 0)
        {
            num++;
            number++;
            result++;
        }
        else
        {
            break;
        }
    }

    printf("\n%i",result);

    return 0;
}
