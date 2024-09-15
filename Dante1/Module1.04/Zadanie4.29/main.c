#include <stdio.h>
#include <math.h>

int main()
{
    int vector[100];
    int size = 0;

    printf("Enter numbers: ");

    for (int i = 0; i < 100; i++)
    {
        int check = scanf("%i", &vector[i]);
        if (check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if (vector[i] == 0)
        {
            break;
        }
        size++;
    }

    if (size < 1)
    {
        printf("Not enough data available");
        return 2;
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + vector[i];
    }
    double temp1 = (double)sum / size;

    double new_sum = 0;
    for (int i = 0; i < size; i++)
    {
        new_sum = new_sum + pow(vector[i] - temp1, 2);
    }
    double new_default = sqrt(new_sum / size);

    printf("\n");

    int temporary = 0;
    for (int i = 0; i < size; i++)
    {
        if (fabs(temp1 - vector[i]) > new_default) // for double type abs() we use fabs instead :)))
        {
            printf("%i ", vector[i]);
            temporary = 1;
        }
    }

    if (temporary == 0)
    {
        printf("Nothing to show");
    }

    return 0;
}
