#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("Enter numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Max: %d\n", (num1 + num2 + abs(num1 - num2)) / 2);
    printf("Min: %d\n", (num1 + num2 - abs(num1 - num2)) / 2);

    return 0;
}
