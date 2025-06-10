#include <stdio.h>

int add(const int *first, const int *second, int* result);
int subtract(const int *first, const int *second, int* result);
int multiply(const int *first, const int *second, int* result);
int divide(const int *first, const int *second, float* result);

int main()
{
    int num1, num2;
    char oper;

    printf("Enter smth: ");
    int check1 = scanf("%i%c%i",&num1,&oper,&num2);
    if(check1 != 3)
    {
        printf("Incorrect input");
        return 1;
    }

    if(oper == '+')
    {
        int result;

        add(&num1, &num2, &result);


        printf("%i",result);
    }
    else if(oper == '-')
    {
        int result;

        subtract(&num1, &num2, &result);


        printf("%i",result);
    }
    else if(oper == '*')
    {
        int result;

        multiply(&num1, &num2, &result);


        printf("%i",result);
    }
    else if(oper == '/')
    {
        if(num2 == 0)
        {
            printf("Operation not permitted");
            return 4;
        }
        float result;

        divide(&num1, &num2, &result);
        

        printf("%f",result);
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    return 0;
}

int divide(const int *first, const int *second, float* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }
    if(*second == 0)
    {
        return 1;
    }

    *result = (float)*first / *second;

    return 0;
}

int multiply(const int *first, const int *second, int* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    *result = *first * *second;

    return 0;
}

int subtract(const int *first, const int *second, int* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    *result = *first - *second;

    return 0;
}

int add(const int *first, const int *second, int* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    *result = *first + *second;

    return 0;
}

