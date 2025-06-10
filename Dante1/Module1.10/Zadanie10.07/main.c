#include <stdio.h>

int sum(const float* tab, unsigned int size, float *result);
int avg(const float* tab, unsigned int size, float *result);
int read_vector_float(float *vec, int size, float stop_value);

int main()
{
    float vector[100];

    printf("Enter numbers: ");

    int size = read_vector_float(vector, 100, 0);

    if (size == -1)
    {
        printf("Not enough data available");
        return 3;
    }

    if (size == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }


    float suma, avge;

    int check1 = sum(vector, size, &suma);
    if (check1 != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    int check2 = avg(vector, size, &avge);
    if (check2 != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nSuma: %.2f", suma);
    printf("\nSred: %.2f\n", avge);

    return 0;
}

int sum(const float *tab, unsigned int size, float *result)
{
    if (tab == NULL || result == NULL || size < 1)
    {
        return 1;
    }

    float sum1 = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        sum1 += *(tab + i);
    }

    *result = sum1;

    return 0;
}

int avg(const float *tab, unsigned int size, float *result)
{
    if (tab == NULL || result == NULL || size < 1)
    {
        return 1;
    }

    float sum2 = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        sum2 += *(tab + i);
    }

    float shit_work = sum2 / size;
    *result = shit_work;

    return 0;
}

int read_vector_float(float *vec, int size, float stop_value)
{
    if (size < 1 || vec == NULL || size > 100)
    {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%f", &*(vec + i));
        if (check != 1)
        {
            return -2;
        }
        if (*(vec + i) == stop_value)
        {
            break;
        }
        counter++;
    }

    return counter;
}
