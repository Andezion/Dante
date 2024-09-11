#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int number = 30 + rand() % (40 - 30);
    printf("%i",number);

    return 0;
}
