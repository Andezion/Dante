#include <stdio.h>

int main()
{
    int day;
    printf("Enter your day:");
    scanf("%i",&day);

    switch (day)
    {
        case 1:
            printf("Poniedzialek");
            break;
        case 2:
            printf("Wtorek");
            break;
        case 3:
            printf("Sroda");
            break;
        case 4:
            printf("Czwartek");
            break;
        case 5:
            printf("Piatek");
            break;
        case 6:
            printf("Sobota");
            break;
        case 7:
            printf("Niedziela");
            break;
        case 0:
            printf("Incorrect input");
            return 1;
        default:
            printf("Incorrect output");
            return 1;
    }
    return 0;

}
