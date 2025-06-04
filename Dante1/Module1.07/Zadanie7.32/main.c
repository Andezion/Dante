#include <stdio.h>

double km2nm (double distance);
double km2lm (double distance);

int main()
{
    double number;
    printf("Enter: ");

    int check = scanf("%lf", &number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(number < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("%.3f\n%.3f", km2nm(number), km2lm(number));
    return 0;
}

double km2nm (double distance)
{
    if(distance < 0)
    {
        return -1;
    }
    return distance * 0.540000;
}

double km2lm (double distance)
{
    if(distance < 0)
    {
        return -1;
    }
    return distance * 0.621371;
}
