#include <stdio.h>

int main()
{
    int number;

    printf("Enter number: ");
    int check = scanf("%i",&number);

    int lol = (check == 1) * 1 + (number % 2 == 0) * 1;
    switch (lol)
    {
        case 1:
            printf("%i is odd",number);
            break;
        case 2:
            printf("%i is even",number);
            break;
        default:
            printf("Incorrect input");
            return 1;
    }

    return 0;
}
