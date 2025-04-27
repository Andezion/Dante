#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int stats(int *sum, float *avg, int num,...)
{
    if(sum == NULL || avg == NULL || num <= 0)
    {
        return 1;
    }

    int counter = 0;

    va_list test;
    va_start(test, num);

    for(int i = 0; i < num; i++)
    {
        int number = va_arg(test, int);
        counter = counter + number;
    }

    *sum = counter;
    *avg = (float)counter / (float)num;

    va_end(test);
    return 0;
}

int main()
{
    int error;

    int number;
    printf("Enter: ");

    error = scanf("%i",&number);
    if(!error)
    {
        printf("Incorrect input");
        return 1;
    }
    if(1 > number || number > 3)
    {
        printf("Incorrect input data");
        return 2;
    }

    int *data = malloc(sizeof(int) * number);
    if(data == NULL)
    {
        printf("Error!");
        return 3;
    }

    printf("Enter: ");
    for(int i = 0; i < number; i++)
    {
        error = scanf("%i",(data + i));
        if(!error)
        {
            printf("Incorrect input");
            free(data);
            return 1;
        }
    }

    int sum;
    float avg;

    error = stats(&sum, &avg, number, *(data + 0), *(data + 1), *(data + 2));
    if(error == 1)
    {
        printf("Incorrect input");
        free(data);
        return 1;
    }

    printf("%i %.6f",sum, avg);

    free(data);
    return 0;
}
