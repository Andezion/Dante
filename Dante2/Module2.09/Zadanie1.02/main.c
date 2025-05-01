#include <stdio.h>
#include <stdint.h>

union bits
{
    uint32_t num;
    struct helper
    {
        unsigned char inte1:1;
        unsigned char inte2:1;
        unsigned char inte3:1;
        unsigned char inte4:1;
        unsigned char inte5:1;
        unsigned char inte6:1;
        unsigned char inte7:1;
        unsigned char inte8:1;
        unsigned char inte9:1;
        unsigned char inte10:1;
        unsigned char inte11:1;
        unsigned char inte12:1;
        unsigned char inte13:1;
        unsigned char inte14:1;
        unsigned char inte15:1;
        unsigned char inte16:1;
        unsigned char inte17:1;
        unsigned char inte18:1;
        unsigned char inte19:1;
        unsigned char inte20:1;
        unsigned char inte21:1;
        unsigned char inte22:1;
        unsigned char inte23:1;
        unsigned char inte24:1;
        unsigned char inte25:1;
        unsigned char inte26:1;
        unsigned char inte27:1;
        unsigned char inte28:1;
        unsigned char inte29:1;
        unsigned char inte30:1;
        unsigned char inte31:1;
        unsigned char inte32:1;
    } popa;
};

int toggle_bit(uint32_t* pvalue, int b);
int set_bit(uint32_t* pvalue, int b);
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);

int main()
{
    int error;

    uint32_t number_cucumber;
    printf("Enter slayyyy: ");
    error = scanf("%u",&number_cucumber);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int in;
    printf("Enter aaaah: ");
    error = scanf("%i",&in);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(in < 0 || in > 31)
    {
        printf("Invalid bit index");
        return 2;
    }

    int type;
    printf("Enter purrrr: ");
    error = scanf("%i",&type);
    if(error != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int res; // i hate myself plz kill me

    switch (type)
    {
        case 0:
            toggle_bit(&number_cucumber, in);
            printf("%x",number_cucumber);
            return 0;
        case 1:
            set_bit(&number_cucumber, in);
            printf("%x",number_cucumber);
            return 0;
        case 2:
            clear_bit(&number_cucumber, in);
            printf("%x",number_cucumber);
            return 0;
        case 3:
            res = isset_bit(&number_cucumber, in);
            printf("%i",res);
            return 0;
        default:
            printf("Invalid operation");
            return 2;
    }
}

int isset_bit(const uint32_t* pvalue, int b)
{
    if(pvalue == NULL)
    {
        return -1;
    }

    union bits a;
    a.num = *pvalue;

    switch (b)
    {
        case 0:
            return a.popa.inte1;
        case 1:
            return a.popa.inte2;
        case 2:
            return a.popa.inte3;
        case 3:
            return a.popa.inte4;
        case 4:
            return a.popa.inte5;
        case 5:
            return a.popa.inte6;
        case 6:
            return a.popa.inte7;
        case 7:
            return a.popa.inte8;
        case 8:
            return a.popa.inte9;
        case 9:
            return a.popa.inte10;
        case 10:
            return a.popa.inte11;
        case 11:
            return a.popa.inte12;
        case 12:
            return a.popa.inte13;
        case 13:
            return a.popa.inte14;
        case 14:
            return a.popa.inte15;
        case 15:
            return a.popa.inte16;
        case 16:
            return a.popa.inte17;
        case 17:
            return a.popa.inte18;
        case 18:
            return a.popa.inte19;
        case 19:
            return a.popa.inte20;
        case 20:
            return a.popa.inte21;
        case 21:
            return a.popa.inte22;
        case 22:
            return a.popa.inte23;
        case 23:
            return a.popa.inte24;
        case 24:
            return a.popa.inte25;
        case 25:
            return a.popa.inte26;
        case 26:
            return a.popa.inte27;
        case 27:
            return a.popa.inte28;
        case 28:
            return a.popa.inte29;
        case 29:
            return a.popa.inte30;
        case 30:
            return a.popa.inte31;
        case 31:
            return a.popa.inte32;
        default:
            return -1;
    }
}

int clear_bit(uint32_t* pvalue, int b)
{
    if(pvalue == NULL)
    {
        return -1;
    }

    union bits a;
    a.num = *pvalue;

    switch (b)
    {
        case 0:
            a.popa.inte1 = 0;
            *pvalue = a.num;
            return 0;
        case 1:
            a.popa.inte2 = 0;
            *pvalue = a.num;
            return 0;
        case 2:
            a.popa.inte3 = 0;
            *pvalue = a.num;
            return 0;
        case 3:
            a.popa.inte4 = 0;
            *pvalue = a.num;
            return 0;
        case 4:
            a.popa.inte5 = 0;
            *pvalue = a.num;
            return 0;
        case 5:
            a.popa.inte6 = 0;
            *pvalue = a.num;
            return 0;
        case 6:
            a.popa.inte7 = 0;
            *pvalue = a.num;
            return 0;
        case 7:
            a.popa.inte8 = 0;
            *pvalue = a.num;
            return 0;
        case 8:
            a.popa.inte9 = 0;
            *pvalue = a.num;
            return 0;
        case 9:
            a.popa.inte10 = 0;
            *pvalue = a.num;
            return 0;
        case 10:
            a.popa.inte11 = 0;
            *pvalue = a.num;
            return 0;
        case 11:
            a.popa.inte12 = 0;
            *pvalue = a.num;
            return 0;
        case 12:
            a.popa.inte13 = 0;
            *pvalue = a.num;
            return 0;
        case 13:
            a.popa.inte14 = 0;
            *pvalue = a.num;
            return 0;
        case 14:
            a.popa.inte15 = 0;
            *pvalue = a.num;
            return 0;
        case 15:
            a.popa.inte16 = 0;
            *pvalue = a.num;
            return 0;
        case 16:
            a.popa.inte17 = 0;
            *pvalue = a.num;
            return 0;
        case 17:
            a.popa.inte18 = 0;
            *pvalue = a.num;
            return 0;
        case 18:
            a.popa.inte19 = 0;
            *pvalue = a.num;
            return 0;
        case 19:
            a.popa.inte20 = 0;
            *pvalue = a.num;
            return 0;
        case 20:
            a.popa.inte21 = 0;
            *pvalue = a.num;
            return 0;
        case 21:
            a.popa.inte22 = 0;
            *pvalue = a.num;
            return 0;
        case 22:
            a.popa.inte23 = 0;
            *pvalue = a.num;
            return 0;
        case 23:
            a.popa.inte24 = 0;
            *pvalue = a.num;
            return 0;
        case 24:
            a.popa.inte25 = 0;
            *pvalue = a.num;
            return 0;
        case 25:
            a.popa.inte26 = 0;
            *pvalue = a.num;
            return 0;
        case 26:
            a.popa.inte27 = 0;
            *pvalue = a.num;
            return 0;
        case 27:
            a.popa.inte28 = 0;
            *pvalue = a.num;
            return 0;
        case 28:
            a.popa.inte29 = 0;
            *pvalue = a.num;
            return 0;
        case 29:
            a.popa.inte30 = 0;
            *pvalue = a.num;
            return 0;
        case 30:
            a.popa.inte31 = 0;
            *pvalue = a.num;
            return 0;
        case 31:
            a.popa.inte32 = 0;
            *pvalue = a.num;
            return 0;
        default:
            return -1;
    }
}

int set_bit(uint32_t* pvalue, int b)
{
    if(pvalue == NULL)
    {
        return -1;
    }

    union bits a;
    a.num = *pvalue;

    switch (b)
    {
        case 0:
            a.popa.inte1 = 1;
            *pvalue = a.num;
            return 0;
        case 1:
            a.popa.inte2 = 1;
            *pvalue = a.num;
            return 0;
        case 2:
            a.popa.inte3 = 1;
            *pvalue = a.num;
            return 0;
        case 3:
            a.popa.inte4 = 1;
            *pvalue = a.num;
            return 0;
        case 4:
            a.popa.inte5 = 1;
            *pvalue = a.num;
            return 0;
        case 5:
            a.popa.inte6 = 1;
            *pvalue = a.num;
            return 0;
        case 6:
            a.popa.inte7 = 1;
            *pvalue = a.num;
            return 0;
        case 7:
            a.popa.inte8 = 1;
            *pvalue = a.num;
            return 0;
        case 8:
            a.popa.inte9 = 1;
            *pvalue = a.num;
            return 0;
        case 9:
            a.popa.inte10 = 1;
            *pvalue = a.num;
            return 0;
        case 10:
            a.popa.inte11 = 1;
            *pvalue = a.num;
            return 0;
        case 11:
            a.popa.inte12 = 1;
            *pvalue = a.num;
            return 0;
        case 12:
            a.popa.inte13 = 1;
            *pvalue = a.num;
            return 0;
        case 13:
            a.popa.inte14 = 1;
            *pvalue = a.num;
            return 0;
        case 14:
            a.popa.inte15 = 1;
            *pvalue = a.num;
            return 0;
        case 15:
            a.popa.inte16 = 1;
            *pvalue = a.num;
            return 0;
        case 16:
            a.popa.inte17 = 1;
            *pvalue = a.num;
            return 0;
        case 17:
            a.popa.inte18 = 1;
            *pvalue = a.num;
            return 0;
        case 18:
            a.popa.inte19 = 1;
            *pvalue = a.num;
            return 0;
        case 19:
            a.popa.inte20 = 1;
            *pvalue = a.num;
            return 0;
        case 20:
            a.popa.inte21 = 1;
            *pvalue = a.num;
            return 0;
        case 21:
            a.popa.inte22 = 1;
            *pvalue = a.num;
            return 0;
        case 22:
            a.popa.inte23 = 1;
            *pvalue = a.num;
            return 0;
        case 23:
            a.popa.inte24 = 1;
            *pvalue = a.num;
            return 0;
        case 24:
            a.popa.inte25 = 1;
            *pvalue = a.num;
            return 0;
        case 25:
            a.popa.inte26 = 1;
            *pvalue = a.num;
            return 0;
        case 26:
            a.popa.inte27 = 1;
            *pvalue = a.num;
            return 0;
        case 27:
            a.popa.inte28 = 1;
            *pvalue = a.num;
            return 0;
        case 28:
            a.popa.inte29 = 1;
            *pvalue = a.num;
            return 0;
        case 29:
            a.popa.inte30 = 1;
            *pvalue = a.num;
            return 0;
        case 30:
            a.popa.inte31 = 1;
            *pvalue = a.num;
            return 0;
        case 31:
            a.popa.inte32 = 1;
            *pvalue = a.num;
            return 0;
        default:
            return -1;
    }
}

int toggle_bit(uint32_t* pvalue, int b)
{
    if(pvalue == NULL)
    {
        return -1;
    }

    union bits a;
    a.num = *pvalue;

    switch (b)
    {
        case 0:
            a.popa.inte1 = a.popa.inte1 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 1:
            a.popa.inte2 = a.popa.inte2 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 2:
            a.popa.inte3 = a.popa.inte3 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 3:
            a.popa.inte4 = a.popa.inte4 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 4:
            a.popa.inte5 = a.popa.inte5 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 5:
            a.popa.inte6 = a.popa.inte6 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 6:
            a.popa.inte7 = a.popa.inte7 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 7:
            a.popa.inte8 = a.popa.inte8 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 8:
            a.popa.inte9 = a.popa.inte9 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 9:
            a.popa.inte10 = a.popa.inte10 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 10:
            a.popa.inte11 = a.popa.inte11 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 11:
            a.popa.inte12 = a.popa.inte12 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 12:
            a.popa.inte13 = a.popa.inte13 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 13:
            a.popa.inte14 = a.popa.inte14 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 14:
            a.popa.inte15 = a.popa.inte15 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 15:
            a.popa.inte16 = a.popa.inte16 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 16:
            a.popa.inte17 = a.popa.inte17 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 17:
            a.popa.inte18 = a.popa.inte18 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 18:
            a.popa.inte19 = a.popa.inte19 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 19:
            a.popa.inte20 = a.popa.inte20 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 20:
            a.popa.inte21 = a.popa.inte21 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 21:
            a.popa.inte22 = a.popa.inte22 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 22:
            a.popa.inte23 = a.popa.inte23 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 23:
            a.popa.inte24 = a.popa.inte24 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 24:
            a.popa.inte25 = a.popa.inte25 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 25:
            a.popa.inte26 = a.popa.inte26 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 26:
            a.popa.inte27 = a.popa.inte27 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 27:
            a.popa.inte28 = a.popa.inte28 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 28:
            a.popa.inte29 = a.popa.inte29 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 29:
            a.popa.inte30 = a.popa.inte30 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 30:
            a.popa.inte31 = a.popa.inte31 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        case 31:
            a.popa.inte32 = a.popa.inte32 == 1 ? 0 : 1;
            *pvalue = a.num;
            return 0;
        default:
            return -1;
    }
}
