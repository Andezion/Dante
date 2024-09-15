#include <stdio.h>

int main()
{
    int vector[100];
    int size = 0;

    int max = -1 * __INT_MAX__;
    int max_i = 0;
    int min = __INT_MAX__;
    int min_i = 0;

    printf("Enter num: ");

    for(int i = 0; i < 100; i++)
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

        if(vector[i] > max)
        {
            max = vector[i];
            max_i = i;
        }
        if(vector[i] < min)
        {
            min = vector[i];
            min_i = i;
        }
    }
    if(size < 2)
    {
        printf("Not enough data available");
        return 2;
    }

    int index = (max_i + min_i) / 2;

    printf("%i ",vector[index]);

    return 0;
}
