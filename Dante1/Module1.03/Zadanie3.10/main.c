#include <stdio.h>

int main()
{
    int number = 0;
    float temp;

    float sum = 0;

    while(number != 10)
    {
        temp = 0;
        printf("Enter %i:",number + 1);

        int check = scanf("%f",&temp);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        number++;
        sum = sum + temp;
    }

    printf("Sum is: %f",sum);

    return 0;
}
