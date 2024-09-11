#include <stdio.h>

int main()
{
    float sum = 0;
    float temp;
    int pointer = 0;

    printf("Enter: ");

    while(pointer != 10)
    {
        temp = 0;
        int check = scanf("%f",&temp);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(temp < 0)
        {
            temp = temp * -1;
        }
        sum = sum + temp;
        pointer++;
    }

    printf("%.2f",sum);

    return 0;
}
