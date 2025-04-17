#include "for_loop.h"
#include <stdio.h>
#include <math.h>

void for_loop(double start, double step, double stop, void (*func)(double))
{
    if (func == NULL)
    {
        return;
    }

    double check = start;

    if (!(step > 0 && check <= stop) && !(step < 0 && check >= stop))
    {
        return;
    }
    (*func)(check);
    for_loop(check + step, step, stop, func);
}

void print_value(double num)
{
    printf("%lf ", num);
}

void print_accumulated(double num)
{
    static double counter = 0.0;
    counter = counter + num;
    printf("%lf ", counter);
}

void print_square(double num)
{
    printf("%lf ", pow(num, 2));
}

void print_abs(double num)
{
    if (num >= 0)
    {
        printf("%lf ", num);
    }
    else
    {
        printf("%lf ", -num);
    }
}
