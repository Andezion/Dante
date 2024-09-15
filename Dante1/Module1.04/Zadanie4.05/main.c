#include <stdio.h>

int main()
{
    float data[10];
    printf("Enter numbers:\n");

    for(int i = 0; i < 10; i++)
    {
        int check = scanf("%f %f",&data[i], &data[i + 1]);
        if(check != 2)
        {
            printf("Input data type error\n");
            return 1;
        }
        i++;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%i - %.2f\n",i,data[i]);
    }

    return 0;
}
