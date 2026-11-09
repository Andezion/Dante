#include <stdio.h>
#include <stdbool.h>

int main()
{
    float temp;
    float result = 0;
    int point = 0;

    while(true)
    {
        printf("\nEnter:");

        if (scanf("%f",&temp) != 1)
        {
            printf("Incorrect input");
            break;
        }

        if(point != 0) {
            result = result * temp;
            printf("%.2f",result);
        } else {
            point = 1;
            printf("%.2f",temp);
            result = temp;
        }
    }

    return 0;
}
