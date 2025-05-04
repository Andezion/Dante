#include <stdio.h>
#include <stdint.h>

unsigned int swap_bits(unsigned int * pvalue, int b1, int b2);

unsigned int swap_bits(unsigned int * pvalue, int b1, int b2)
{
    if(pvalue == NULL || b1 > 31 || b2 > 32 || b1 < 0 || b2 < 0)
    {
        return 1;
    }

    int number = 1;

    if(!(!((*pvalue) & number << b1) || (*pvalue) & number << b2))
    {
        (* pvalue) = (* pvalue) | number << b2;
        (* pvalue) = (* pvalue) & ~(number << b1);
    }
    if(!(!((*pvalue) & number << b2) || (*pvalue) & number << b1))
    {
        (* pvalue) = (* pvalue) | number << b1;
        (* pvalue) = (* pvalue) & ~(number << b2);
    }

    return 0;
}

int main()
{
    int error;

    uint32_t value;
    printf("Enter number: ");
    error = scanf("%u", &value);
    if (error != 1)
    {
        printf("\nIncorrect input");
        return 1;
    }

    int index1;
    printf("\nEnter 1st: ");
    error = scanf("%i", &index1);
    if (error != 1)
    {
        printf("\nIncorrect input");
        return 1;
    }
    if(index1 < 0 || index1 > 32)
    {
        printf("\nIncorrect input");
        return 1;
    }

    int index2;
    printf("\nEnter 2nd: ");
    error = scanf("%i", &index2);
    if (error != 1)
    {
        printf("\nIncorrect input");
        return 1;
    }
    if(index2 < 0 || index2 > 32)
    {
        printf("\nIncorrect input");
        return 1;
    }

    if(index1 == index2)
    {
        printf("\nIncorrect input");
        return 1;
    }

    uint32_t bit1 = (value >> index1) & 1;
    uint32_t bit2 = (value >> index2) & 1;

    if (bit1 != bit2)
    {
        value ^= (1 << index1) | (1 << index2);
    }

    printf("\nResult: %u", value);

    return 0;
}
