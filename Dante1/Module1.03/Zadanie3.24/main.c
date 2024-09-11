#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int data[10];
    for(int i = 0; i < 10; i++)
    {
        int number = rand();
        data[i] = number;
        printf("%i ",data[i]);
    }

    return 0;
}
