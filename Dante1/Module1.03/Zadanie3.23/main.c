#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int number = rand();
    printf("%i ",number);
    return 0;
}
