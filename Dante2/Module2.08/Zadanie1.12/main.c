#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int checker(char *some_number_maybe)
{
    if (*some_number_maybe == '-' || *some_number_maybe == '+')
    {
        some_number_maybe++;
    }
    if (*some_number_maybe == '\0')
    {
        return 0;
    }
    while (*some_number_maybe)
    {
        if (!isdigit(*some_number_maybe))
        {
            return 0;
        }
        some_number_maybe++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments");
        return 9;
    }

    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        if (!checker(*(argv + i)))
        {
            printf("Incorrect input");
            return 1;
        }
        sum = sum + atoi(*(argv + i));
    }
    printf("%i\n", sum);
    return 0;
}
