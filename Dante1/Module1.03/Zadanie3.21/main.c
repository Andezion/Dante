#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float min, max;

    printf("Enter min: ");
    int check = scanf("%f",&min);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter max: ");
    int check2 = scanf("%f",&max);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    else if(min > max)
    {
        printf("Incorrect range");
        return 2;
    }
    else
    {
        for(float i = min; i <= max; i = i + 0.25)
        {
            printf("%.2f ",i);
        }
    }
    return 0;
}
