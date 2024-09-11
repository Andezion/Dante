#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int number;
    for(int i = 0; i < 10; i++)
    {
        number = 10 + rand() % (20 - 10 + 1);
        printf("%i ",number);
    }

    return 0;
}
