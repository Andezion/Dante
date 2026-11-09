#include <stdio.h>

int main() {
    int num;
    unsigned long long result = 1;

    printf("Enter: ");

    if (scanf("%d",&num) != 1 || (num < 0 || num >= 21))
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
