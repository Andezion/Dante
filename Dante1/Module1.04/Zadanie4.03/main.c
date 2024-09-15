
#include <stdio.h>

int main()
{
    int data[11];
    for(int i = 0; i < 11; i++)
    {
        data[i] = i;
    }
    for(int i = 0; i < 11; i++)
    {
        printf("%i ",data[i]);
    }
    printf("\n");
    return 0;
}
