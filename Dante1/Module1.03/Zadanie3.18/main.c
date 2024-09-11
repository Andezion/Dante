#include <stdio.h>

int main()
{
    int sum1 = 0, sum2 = 0;
    int temp;

    printf("Enter:\n");
    while(1)
    {
        temp = 0;

        int check = scanf("%i",&temp);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(temp == -1)
        {
            break;
        }
        if(temp % 2 == 0)
        {
            sum1 = sum1 + temp;
        }
        else
        {
            sum2 = sum2 + temp;
        }
    }

    printf("%i\n%i",sum1,sum2);

    return 0;
}
