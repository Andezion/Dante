#include <stdio.h>

int main()
{
    double eps = 1e-4;
    double sum = 0.0;
    int n = 1;

    while (1)
    {
        double temp = 1.0 / (n * (n + 1.0));

        if (temp < eps)
        {
            break;
        }

        sum = sum + temp;
        n++;
    }

    printf("%i %.4f",n-1,sum);

    return 0;
}
