#include <stdio.h>
#include <math.h>
#include "functions.h"

int main()
{
    int error;

    int type;
    printf("Enter type: ");

    error = scanf("%i",&type);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(type != 0 && type != 1)
    {
        printf("Incorrect input data");
        return 2;
    }

    if(type == 0)
    {
        int a, b;
        printf("Enter numbers: ");

        error = scanf("%i %i", &a, &b);
        if(error != 2)
        {
            printf("Incorrect input");
            return 1;
        }

        int val1 = SQR(a);
        int val2 = SQR(b);
        int val3 = MIN(a, b);
        int val4 = MAX(a, b);

        printf("%i\n%i\n%i\n%i",val1, val2, val4, val3);
    }
    else
    {
        float a, b;
        printf("Enter numbers: ");

        error = scanf("%f %f", &a, &b);
        if(error != 2)
        {
            printf("Incorrect input");
            return 1;
        }

        float val1 = SQR(a);
        float val2 = SQR(b);
        float val3 = MIN(a, b);
        float val4 = MAX(a, b);

        printf("%.6f\n%.6f\n%.6f\n%.6f",val1, val2, val4, val3);
    }

    return 0;
}
