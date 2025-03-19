#include <stdio.h>

union
{
    unsigned int unsigned_int;

    struct
    {
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;

        unsigned char bit9 : 1;
        unsigned char bit10 : 1;
        unsigned char bit11 : 1;
        unsigned char bit12 : 1;
        unsigned char bit13 : 1;
        unsigned char bit14 : 1;
        unsigned char bit15 : 1;
        unsigned char bit16 : 1;

        unsigned char bit17 : 1;
        unsigned char bit18 : 1;
        unsigned char bit19 : 1;
        unsigned char bit20 : 1;
        unsigned char bit21 : 1;
        unsigned char bit22 : 1;
        unsigned char bit23 : 1;
        unsigned char bit24 : 1;

        unsigned char bit25 : 1;
        unsigned char bit26 : 1;
        unsigned char bit27 : 1;
        unsigned char bit28 : 1;
        unsigned char bit29 : 1;
        unsigned char bit30 : 1;
        unsigned char bit31 : 1;
        unsigned char bit32 : 1;

    } bit;

} bit_set;

int main()
{
    int error;
    unsigned int input;

    printf("Enter: ");
    error = scanf("%u", &input);
    if (error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    bit_set.unsigned_int = input;

    int result = (bit_set.bit.bit1 == 1) + (bit_set.bit.bit2 == 1) + (bit_set.bit.bit3 == 1) + (bit_set.bit.bit4 == 1) +
                 (bit_set.bit.bit5 == 1) + (bit_set.bit.bit6 == 1) + (bit_set.bit.bit7 == 1) + (bit_set.bit.bit8 == 1) +
                 (bit_set.bit.bit9 == 1) + (bit_set.bit.bit10 == 1) + (bit_set.bit.bit11 == 1) + (bit_set.bit.bit12 == 1) +
                 (bit_set.bit.bit13 == 1) + (bit_set.bit.bit14 == 1) + (bit_set.bit.bit15 == 1) + (bit_set.bit.bit16 == 1) +
                 (bit_set.bit.bit17 == 1) + (bit_set.bit.bit18 == 1) + (bit_set.bit.bit19 == 1) + (bit_set.bit.bit20 == 1) +
                 (bit_set.bit.bit21 == 1) + (bit_set.bit.bit22 == 1) + (bit_set.bit.bit23 == 1) + (bit_set.bit.bit24 == 1) +
                 (bit_set.bit.bit25 == 1) + (bit_set.bit.bit26 == 1) + (bit_set.bit.bit27 == 1) + (bit_set.bit.bit28 == 1) +
                 (bit_set.bit.bit29 == 1) + (bit_set.bit.bit30 == 1) + (bit_set.bit.bit31 == 1) + (bit_set.bit.bit32 == 1);

    if(result % 2 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }


    return 0;
}
