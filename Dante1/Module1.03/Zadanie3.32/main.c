#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int counter = 0;
    int iterator = 0;

    int random;

    while(iterator != 100)
    {
        random = -1000 + rand() % 2001;
        if(abs(random) <= 100)
        {
            counter++;
        }
        iterator++;
    }

    printf("\n%i",counter);

    return 0;
}
