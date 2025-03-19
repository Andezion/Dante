#include <stdio.h>
#include "byte_set.h"

int main()
{
    int error;

    union byte_set test;
    printf("Enter: ");

    error = scanf("%i",&test.number);
    if(!error)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");
    for(unsigned long long i = 0; i < sizeof(int); i++)
    {
        printf("%u ",(unsigned char) *(test.text + i));
    }

    return 0;
}
