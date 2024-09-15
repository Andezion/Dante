#include <stdio.h>

int main()
{
    int data[10];
    int max = -1 * __INT_MAX__;
    int min = __INT_MAX__;
    printf("Enter smth: ");

    int sum = 0;
    for(int i = 0; i < 10; i = i + 2)
    {
        int check = scanf("%i %i",&data[i],&data[i + 1]);
        if(check != 2)
        {
            printf("Input data type error");
            return 1;
        }
        sum = sum + data[i] + data[i + 1];
        if(max < data[i])
        {
            max = data[i];
        }
        if(max < data[i + 1])
        {
            max = data[i + 1];
        }
        if(min > data[i])
        {
            min = data[i];
        }
        if(min > data[i + 1])
        {
            min = data[i + 1];
        }
    }

    printf("%.4f\n%i\n%i\n",(float)sum/10, max, min);

    return 0;
}
