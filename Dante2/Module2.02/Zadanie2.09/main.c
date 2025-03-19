#include <stdio.h>
#include <math.h>


struct complex_t
{
    float re;
    float im;
};

int read(struct complex_t* cp);
struct complex_t* set(struct complex_t* cp, float re, float im, int *err_code);
float complex_abs(struct complex_t* cp, int * err_code);
void show(const struct complex_t* cp);

int add(const struct complex_t *first, const struct complex_t *second, struct complex_t* result);
int subtract(const struct complex_t *first, const struct complex_t *second, struct complex_t* result);
int multiply(const struct complex_t *first, const struct complex_t *second, struct complex_t* result);
int divide(const struct complex_t *first, const struct complex_t *second, struct complex_t* result);

int main()
{
    int error;
    struct complex_t first;
    struct complex_t second;

    printf("Enter: ");
    error = read(&first);
    if(error != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Enter: ");
    error = read(&second);
    if(error != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    int err_code1;
    float module1 = complex_abs(&first, &err_code1);
    if(module1 < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    struct complex_t result;
    int result_of_operations;

    add(&first, &second, &result);

    show(&result);

    subtract(&first, &second, &result);

    show(&result);

    multiply(&first, &second, &result);

    show(&result);

    result_of_operations = divide(&first, &second, &result);
    if(result_of_operations == 2)
    {
        printf("Operation not permitted");
        return 0;
    }
    /*if(result_of_operations == 1)
    {
        printf("Incorrect input");
        return 1;
    }*/
    else
    {
        show(&result);
    }

    return 0;
}

int add(const struct complex_t *first, const struct complex_t *second, struct complex_t* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    result->re = first->re + second->re;
    result->im = first->im + second->im;

    return 0;
}

int subtract(const struct complex_t *first, const struct complex_t *second, struct complex_t* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    result->re = first->re - second->re;
    result->im = first->im - second->im;

    return 0;
}

int multiply(const struct complex_t *first, const struct complex_t *second, struct complex_t* result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    result->re = first->re * second->re - first->im * second->im;
    result->im = first->re * second->im + first->im * second->re;

    return 0;
}

int divide(const struct complex_t *first, const struct complex_t *second, struct complex_t* result)
{
    if (first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }

    float some_shit_idk_help_me = second->re * second->re + second->im * second->im;
    if (some_shit_idk_help_me <= 0)
    {
        return 2;
    }

    result->re = (first->re * second->re + first->im * second->im) / some_shit_idk_help_me;
    result->im = (first->im * second->re - first->re * second->im) / some_shit_idk_help_me;

    return 0;
}

int read(struct complex_t* cp)
{
    if(cp == NULL)
    {
        return 2;
    }

    float re, im;
    char oper;

    int error;

    error = scanf("%f%ci%f",&re,&oper,&im);
    if(error != 3 || (oper != '-' && oper != '+') || im < 0)
    {
        return 1;
    }

    while(getchar() != '\n');

    int error_code;

    if(oper == '-')
    {
        im = -1 * im;
        if(set(cp, re, im, &error_code) == NULL)
        {
            return 1;
        }
    }
    else if(oper == '+')
    {
        if(set(cp, re, im, &error_code) == NULL)
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }

    return 0;
}

float complex_abs(struct complex_t* cp, int *err_code)
{
    if(cp == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return -1.0f;
    }

    float module = sqrtf(cp->re * cp->re + cp->im * cp->im);
    if(err_code == NULL)
    {
        return module;
    }

    *err_code = 0;
    return module;
}

void show(const struct complex_t* cp)
{
    if(cp == NULL)
    {
        return;
    }

    if(cp->im < 0)
    {
        printf("%.2f - i%.2f\n",cp->re,fabsf(cp->im));
    }
    else
    {
        printf("%.2f + i%.2f\n",cp->re,fabsf(cp->im));
    }
}

struct complex_t* set(struct complex_t* cp, float re, float im, int *err_code)
{
    if(cp == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    cp->im = im;
    cp->re = re;

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return cp;
}
