#include <stdio.h>

int main() 
{
    float T[100] = { 0 };


    int size;
    printf("Enter size: ");

    int check = scanf("%i",&size);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(size < 1 || size > 100)
    {
        printf("Incorrect input data");
        return 2;
    }

    float *new = T;

    float sum = 0;

    printf("Enter data: ");
    for(int i = 0; i < size; i++)
    {
        int check1 = scanf("%f",&*(new + i));
        if(check1 != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        sum = sum + *(new + i);
    }

    for(int i = size - 1; i >= 0; i--)
    {
        printf("%.6f ",*(new + i));
    }

    printf("\n%.2f\n",sum);
    printf("%.2f\n",sum / size);

    return 0;
}
