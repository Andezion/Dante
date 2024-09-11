#include <stdio.h>

int main()
{
    float temp;
    float max = -1000;
    float min = 1000;
    float sum = 0;

    printf("Enter:\n");

    int counter = 0;
    while (1)
    {
        temp = 0;
        int check = scanf("%f", &temp);
        if (check != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        if(temp == -1)
        {
            break;
        }

        if (max < temp)
        {
            max = temp;
        }
        if (min > temp || counter == 0)
        {
            min = temp;
        }

        sum = sum + temp;
        counter++;
    }

    printf("Min: %.2f\nMax: %.2f\nAverage: %.2f", min, max, sum / (float)counter);

    return 0;
}
