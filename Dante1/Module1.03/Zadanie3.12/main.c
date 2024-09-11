#include <stdio.h>

int main()
{
    unsigned long long result = 1;
    int num;

    printf("Enter: ");

    int check = scanf("%i",&num);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(num < 0 || num >= 21)
    {
        printf("Incorrect input");
        return 1;
    }

    int pointer = 0;
    while(pointer != num)
    {
        result = result + result * pointer;
        pointer++;
    }

    printf("Result: %llu",result);

    return 0;
}
