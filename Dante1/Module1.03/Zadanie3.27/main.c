#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int number;
    int sum = 0;
    for(int i = 0; i < 100; i++)
    {
        number = 10 + rand() % (20 - 10 + 1);

        sum = sum + number;
    }

    printf("%i ",sum);

    return 0;
}
