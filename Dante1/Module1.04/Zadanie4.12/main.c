#include <stdio.h>

int main()
{
    int vector[1000];
    int size = 0;
    int sum = 0;

    printf("Enter smth: ");

    for(int i = 0; i < 1000; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(vector[i] == 0)
        {
            break;
        }
        size++;
        sum = sum + vector[i];
    }

    if(size < 1)
    {
        printf("Brak danych");
        return 0;
    }

    int sum1 = 0, sum2 = 0;
    float middle = (float)sum / (float)size;

    for(int i = 0; i < size; i++)
    {
        if((float)vector[i] > middle)
        {
            sum1  = sum1 + vector[i];
        }
        if((float)vector[i] < middle)
        {
            sum2 = sum2 + vector[i];
        }
    }

    printf("%.2f\n%i\n%i",middle,sum1,sum2);

    return 0;
}
