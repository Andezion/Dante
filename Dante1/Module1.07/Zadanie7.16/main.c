#include <stdio.h>
#include <math.h>

double mySin(double x, int n);
double myCos(double x, int n);

double helper (int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
        return n * helper(n - 1);
    }
}

int main()
{
    float kat;
    int num;

    printf("Enter kat: ");
    int check = scanf("%f",&kat);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter num: ");
    int check2 = scanf("%i",&num);
    if(check2 != 1 || num < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%f %f", mySin(kat,num), myCos(kat,num));

    return 0;
}

double mySin(double x, int n)
{
    if(n < 0)
    {
        return -1;
    }

    double sum = 0;

    for(int i = 0; i <= n; i++)
    {
        sum = sum + (pow(-1, i) / helper(2 * i + 1)) * pow(x, 2 * i + 1);
    }

    return sum;
}

double myCos(double x, int n)
{
    if(n < 0)
    {
        return -1;
    }

    double sum = 0;

    for(int i = 0; i <= n; i++)
    {
        sum = sum + (pow(-1, i) / helper(2 * i)) * pow(x, 2 * i);
    }

    return sum;
}
