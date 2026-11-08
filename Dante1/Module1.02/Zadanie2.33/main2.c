#include <stdio.h>

int main(void)
{
    double x = 0;
    char money = 0;

    printf("Podaj pierwsza liczbe: ");
    int ok = scanf("%lf", &x) == 1 && x > 0
          && printf("Podaj symbol operacji: ")
          && scanf(" %c", &money) == 1;

    switch (ok * money)
    {
        case 'e':
            printf("%.2f", x / 4.2074);
            return 0;
        case 'f':
            printf("%.2f", x / 4.7073);
            return 0;
        case 'd':
            printf("%.2f", x / 3.5382);
            return 0;
        default:
            printf("Incorrect input");
            return 1;
    }
}
