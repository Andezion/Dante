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

    printf("Enter kat: ");
    int check = scanf("%f",&kat);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int nSin = 0;
    int nCos = 0;

    while (fabs(mySin(kat, nSin) - sinf(kat)) >= 0.0001)
    {
        nSin++;
    }

    while (fabs(myCos(kat, nCos) - cosf(kat)) >= 0.0001)
    {
        nCos++;
    }

    printf("%i\n%i\n", nSin, nCos);

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
