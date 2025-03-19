#include <stdio.h>

union
{
    unsigned int unsigned_int;

    struct
    {
        unsigned short int word1;
        unsigned short int word2;
    } word;

    struct
    {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } byte;

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

    printf("%u\n", bit_set.unsigned_int);
    printf("%u %u\n", bit_set.word.word1, bit_set.word.word2);
    printf("%u %u %u %u\n", bit_set.byte.byte1, bit_set.byte.byte2, bit_set.byte.byte3, bit_set.byte.byte4);
    printf("%u%u%u%u%u%u%u%u %u%u%u%u%u%u%u%u %u%u%u%u%u%u%u%u %u%u%u%u%u%u%u%u\n",
           bit_set.bit.bit8, bit_set.bit.bit7, bit_set.bit.bit6, bit_set.bit.bit5, bit_set.bit.bit4, bit_set.bit.bit3, bit_set.bit.bit2, bit_set.bit.bit1,
           bit_set.bit.bit16, bit_set.bit.bit15, bit_set.bit.bit14, bit_set.bit.bit13, bit_set.bit.bit12, bit_set.bit.bit11, bit_set.bit.bit10, bit_set.bit.bit9,
           bit_set.bit.bit24, bit_set.bit.bit23, bit_set.bit.bit22, bit_set.bit.bit21, bit_set.bit.bit20, bit_set.bit.bit19, bit_set.bit.bit18, bit_set.bit.bit17,
           bit_set.bit.bit32, bit_set.bit.bit31, bit_set.bit.bit30, bit_set.bit.bit29, bit_set.bit.bit28, bit_set.bit.bit27, bit_set.bit.bit26, bit_set.bit.bit25);

    return 0;
}
