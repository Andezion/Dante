#include <stdio.h>

int main()
{
    int vector[100];
    int size = 0;
    int sum = 0;
    int min = __INT_MAX__;
    int max = -1 * __INT_MAX__;

    printf("Enter some shit: ");

    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(vector[i] == -1)
        {
            break;
        }
        sum = sum + vector[i];
        if(max < vector[i])
        {
            max = vector[i];
        }
        if(min > vector[i])
        {
            min = vector[i];
        }
        size++;
    }

    printf("%i\n%i\n%i\n%f\n%i\n",size,min,max,(float)sum/(float)size,sum);

    for(int i = 0; i < size; i++)
    {
        if(vector[i] == min)
        {
            printf("%i ",i);
        }
    }
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        if(vector[i] == max)
        {
            printf("%i ",i);
        }
    }
    printf("\n");

    return 0;
}
