#include <stdio.h>

int main()
{
    float x;
    double euro = 4.2074;
    double funt = 4.7073;
    double dolar = 3.5382;
    char money;
    printf("Podaj pierwsza liczbe:");
    int scan = scanf("%f", &x);
    switch (scan)
    {
        case 1:
            switch (x >= 0)
            {
                case 1:
                    break;
                default:
                    printf("Incorrect input");
                    return 1;
            }
            break;
        default:
            printf("Incorrect input");
            return 1;
    }

    printf("Podaj symbol operacji:");
    scanf("%1s", &money);
    switch (money)
    {
        case 'e':
            printf("%.2f", x / euro);
            break;
        case 'f':
            printf("%.2f", x / funt);
            break;
        case 'd':
            printf("%.2f", x / dolar);
            break;
        default:
            printf("Incorrect input");
            return 1;
    }
    return 0;
}
