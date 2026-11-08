#include <stdio.h>

int main()
{
    int ocena;
    printf("Enter your mark:");
    scanf("%d",&ocena);

    switch (ocena)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Dzien roboczy");
            break;
        case 6:
        case 7:
            printf("Weekend");
            break;
        default:
            printf("Incorrect input");
            return 1;
    }
    return 0;

}
