#ifndef WINAPI_BIT_SET_H
#define WINAPI_BIT_SET_H

union bit_set
{
    signed char letter;

    struct array
    {
        unsigned char x1: 1;
        unsigned char x2: 1;
        unsigned char x3: 1;
        unsigned char x4: 1;
        unsigned char x5: 1;
        unsigned char x6: 1;
        unsigned char x7: 1;
        unsigned char x8: 1;
    } array;
};

#endif //WINAPI_BIT_SET_H
