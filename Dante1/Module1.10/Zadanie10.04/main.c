#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));

    int vector[20];

    int *new_vector = vector;
    for(int i = 0; i < 20; i++)
    {
        *(new_vector + i) = rand() % 10;
        printf("%i ",*(new_vector + i));
    }

    printf("\n");

    for(int i = 0; i < 20; i = i + 2)
    {
        printf("%i ",*(new_vector + i));
    }

    return 0;
}
