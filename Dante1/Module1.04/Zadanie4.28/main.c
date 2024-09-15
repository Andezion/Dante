#include <stdlib.h>
#include <stdio.h>

int main()
{
    int vector[100];
    int size = 0;

    int max = -1 * __INT_MAX__;
    int min = __INT_MAX__;

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
        }
        if(vector[i] < min)
        {
            min = vector[i];
        }
    }
    if(size < 2)
    {
        printf("Not enough data available");
        return 2;
    }

    int suma = 0;
    int counter = 0;
    for(int i = 0; i < size; i++)
    {
        if(vector[i] == max || vector[i] == min)
        {
            suma = suma + i;
            counter++;
        }
    }

    if(counter == 0)
    {
        printf("\nNothing to show");
        return 1;
    }


    printf("\n%i ",vector[suma / counter]);
    return 0;
}
