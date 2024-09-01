#include <stdio.h>

int main()
{
    int ocena;
    printf("Enter your mark:");
    scanf("%i",&ocena);

    switch (ocena)
    {
        case 1:
            printf("Dzien roboczy");
            break;
        case 2:
            printf("Dzien roboczy");
            break;
        case 3:
            printf("Dzien roboczy");
            break;
        case 4:
            printf("Dzien roboczy");
            break;
        case 5:
            printf("Dzien roboczy");
            break;
        case 6:
            printf("Weekend");
            break;
        case 7:
            printf("Weekend");
            break;
        default:
            printf("Incorrect input");
            return 1;
    }
    return 0;

}
