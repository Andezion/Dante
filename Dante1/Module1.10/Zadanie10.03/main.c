#include <stdio.h>

int main() 
{
    int T[10];

    int *new = T;

    for(int i = 0; i < 10; i++)
    {
        *(new+ i) = i;
        printf("%i ",*(new + i));
    }

    return 0;
}
