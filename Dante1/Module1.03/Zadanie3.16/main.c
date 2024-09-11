#include <stdio.h>

int main()
{
    float temp;
    float result = 0;
    int point = 0;

    while(1)
    {
        temp = 0;

        printf("\nEnter:");

        int check = scanf("%f",&temp);
        if(check != 1)
        {
            printf("Incorrect input");
            break;
        }
        if(point != 0)
        {
            result = result * temp;
            printf("%.2f",result);
        }
        else
        {
            point = 1;
            printf("%.2f",temp);
            result = temp;
        }
    }

    return 0;
}
