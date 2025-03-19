#ifndef WINAPI_BYTE_SET_H
#define WINAPI_BYTE_SET_H

union byte_set
{
    int number;
    char text[sizeof(int)];
};

#endif //WINAPI_BYTE_SET_H
