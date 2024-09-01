#include <stdio.h>
#include <ctype.h>

int main()
{
    int number;
    printf("Enter smth: ");

    int test = scanf("%d", &number);

    int result = (number > 0) * 1 + (number < 0) * 2 + (number == 0) * 3 + (test == 1) * 1;

    switch(result)
    {
        case 2:
            printf("%i is positive", number);
            return 0;
        case 3:
            printf("%i is negative", number);
            return 0;
        case 4:
            printf("%i is equal to 0", number);
            return 0;
        default:
            printf("Incorrect input");
            return 1;
    }
}
