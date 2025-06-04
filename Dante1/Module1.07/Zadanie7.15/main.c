#include <stdio.h>
#include <math.h>

float toRadian(float a);
float toDegree(float a);

int main()
{
    int type;
    printf("Enter type: ");
    int check = scanf("%i", &type);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if(type == 1)
    {
        float kat;

        printf("Enter kat: ");
        int check1 = scanf("%f",&kat);
        if(check1 != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        printf("Result: %.2f", toRadian(kat));
    }
    else if(type == 2)
    {
        float kat;

        printf("Enter kat: ");
        int check1 = scanf("%f",&kat);
        if(check1 != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        printf("Result: %.2f", toDegree(kat));
    }
    else
    {
        printf("Incorrect input ");
        return 1;
    }
    return 0;
}

float toRadian(float a)
{
    return a * M_PI / 180;
}

float toDegree(float a)
{
    return a * 180 / M_PI;
}
