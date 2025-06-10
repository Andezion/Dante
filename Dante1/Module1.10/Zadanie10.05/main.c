#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));

    float vector[20];

    float *new_vector = vector;
    for(int i = 0; i < 20; i++)
    {
        float a = rand() % 20;
        float b = 1 + rand() % 10;
        *(new_vector + i) = a / b;
        printf("%.1f ",*(new_vector + i));
    }

    printf("\n");

    for(int i = 0; i < 20; i = i + 2)
    {
        printf("%.1f ",*(new_vector + i));
    }

    return 0;
}
