#include <stdio.h>
#include <math.h>

float average(const int tab[], int size);
float stdDev(const int tab[], int size);

int main()
{
    int tab[100];
    int size = 0;

    printf("Enter tab:\n");

    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&tab[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(tab[i] == 0)
        {
            size = i;
            break;
        }
        size++;
    }

    if(size < 1)
    {
        printf("\nNot enough data available");
        return 2;
    }

    printf("%.2f\n%.2f", average(tab, size), stdDev(tab,size));

    return 0;
}

float average(const int tab[], int size)
{
    if(size <= 0 || tab == NULL)
    {
        return -1;
    }
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum = sum + tab[i];
    }

    float result = (float)sum / size;

    return result;
}

float stdDev(const int tab[], int size)
{
    if(size <= 0 || tab == NULL)
    {
        return -1;
    }
    float middle = average(tab,size);
    float sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum = sum + powf((tab[i] - middle),2);
    }

    float result = sqrtf(sum / size);

    return result;
}
