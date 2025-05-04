#ifndef CROSSWORD_FUNCTIONS_H
#define CROSSWORD_FUNCTIONS_H

#define COUNT_BITS(number, to_change_x, to_change_y)\
do\
{\
    *(to_change_y) = 0;\
    *(to_change_x) = 0;\
\
    unsigned long long some_shit = (number);\
    int i = (int)(sizeof(number) * 8) - 1;\
    while(i >= 0)\
    {\
        if (!(some_shit & 1ULL << i))\
        {\
            (*(to_change_y)) = (*(to_change_y)) + 1;\
        }\
        else\
        {\
            (*(to_change_x)) = (*(to_change_x)) + 1;\
        }\
        i--;\
    }\
} while(0);                                                  \

#define DISPLAY_BITS(number)\
do\
{\
    int i = (int)(sizeof(number) * 8) - 1;\
    while(i >= 0)       \
    {               \
        if((number) & 1ULL << i)\
        {\
            printf("1");   \
        }\
        else\
        {\
            printf("0"); \
        }\
        i--;\
    }\
}while(0);\

#define REVERSE_BITS(number)      \
do\
{           \
    unsigned long long result = 0;    \
    int j = (int)(sizeof(*(number)) * 8) - 1;        \
    for(int i = 0; i < ((int)(sizeof(*(number)) * 8)); i++)  \
    {           \
        if((*(number)) & (1ULL << i))    \
        {\
            result |= (1ULL << j);    \
        }           \
        j--;       \
    }           \
    *number = result;   \
} while(0);\

#endif //CROSSWORD_FUNCTIONS_H
