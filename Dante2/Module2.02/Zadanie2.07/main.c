#include <stdio.h>
#include <math.h>

struct complex_t
{
    float re;
    float im;
};

struct complex_t* set(struct complex_t* cp, float re, float im, int *err_code);
float complex_abs(struct complex_t* cp, int * err_code);
void show(const struct complex_t* cp);

int main()
{
    float re1, im1;
    char oper1;

    int error;

    printf("Enter: ");
    error = scanf("%f%ci%f",&re1,&oper1,&im1);
    if(error != 3 || (oper1 != '-' && oper1 != '+') || im1 < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    while(getchar() != '\n');

    float re2, im2;
    char oper2;

    printf("Enter: ");
    error = scanf("%f%ci%f",&re2, &oper2, &im2);
    if(error != 3 || (oper2 != '-' && oper2 != '+') || im2 < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    while(getchar() != '\n');

    struct complex_t cp1;
    struct complex_t cp2;

    int error_code1;
    int error_code2;

    if(oper1 == '-')
    {
        im1 = -1 * im1;
        if(set(&cp1, re1, im1, &error_code1) != NULL)
        {
            show(&cp1);
        }
    }
    else if(oper1 == '+')
    {
        if(set(&cp1, re1, im1, &error_code1) != NULL)
        {
            show(&cp1);
        }
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");

    if(oper2 == '-')
    {
        im2 = -1 * im2;
        if(set(&cp2, re2, im2, &error_code2) != NULL)
        {
            show(&cp2);
        }
    }
    else if(oper2 == '+')
    {
        if(set(&cp2, re2, im2, &error_code2) != NULL)
        {
            show(&cp2);
        }
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");

    float module1 = complex_abs(&cp1, &error_code1);
    float module2 = complex_abs(&cp2, &error_code2);

    if(module1 > module2)
    {
        printf("FIRST");
    }
    else if(module1 < module2)
    {
        printf("SECOND");
    }
    else
    {
        printf("EQUAL");
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
        printf("%.2f - i%.2f",cp->re,fabsf(cp->im));
    }
    else
    {
        printf("%.2f + i%.2f",cp->re,fabsf(cp->im));
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
