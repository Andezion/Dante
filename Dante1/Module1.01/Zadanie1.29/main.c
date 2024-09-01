#include <stdio.h>
#include <stdlib.h>


int main()
{
    int num1, num2;
    printf("Enter numbers: ");
    scanf("%i %i", &num1, &num2);

    int max = (num1 + num2 + abs(num1 - num2)) / 2;
    int min = (num1 + num2 - abs(num1 - num2)) / 2;
    printf("Max: %i\n",max);
    printf("Min: %i\n",min);

    return 0;
}
