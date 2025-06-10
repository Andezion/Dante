#include <stdio.h>

int main()
{
    int tab[] = {67305985, 134678021, 202050057 };

    char *bytes = (char *)tab;
    for(size_t i = 0; i < sizeof(tab); i++)
    {
        printf("%hhu ", *(bytes+i));
    }
    return 0;
}
