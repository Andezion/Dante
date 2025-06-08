#include <stdio.h>
#include "vector_utils.h"
#include "statistics.h"

int main()
{
    int tab[150];

    printf("Enter: ");
    int size = read_vector(tab,150,0);
    if(size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 3;
    }

    float num1 = average(tab,size);
    float num2 = median(tab,size);
    int num3 = mode(tab,size);

    printf("\n%.2f\n%i\n%.2f",num2,num3,num1);
    return 0;
}
