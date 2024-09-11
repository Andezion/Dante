#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int n;

    printf("Enter number: ");
    scanf("%i", &n);

    if (n <= 0 || n > 10)
    {
        printf("Improper input data");
        return 1;
    }


    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double number = ((double)rand() / RAND_MAX) * 10 - 5;
        printf("%.6f\n", number);
        sum = sum + number;
    }

    printf("%.4f\n", sum);

    return 0;
}
