#include <stdio.h>
#include <math.h>

void print_complex(double re, double im)
{
    printf("%.3f %c i%.3f", re, "+-"[im < 0], fabs(im));
}

int main()
{
    double a, b, c, d;

    printf("Podaj czesc rzeczywista pierwszej liczby zespolonej: ");
    scanf("%lf", &a);
    printf("Podaj czesc urojona pierwszej liczby zespolonej: ");
    scanf("%lf", &b);
    printf("Podaj czesc rzeczywista drugiej liczby zespolonej: ");
    scanf("%lf", &c);
    printf("Podaj czesc urojona drugiej liczby zespolonej: ");
    scanf("%lf", &d);

    double denom = c * c + d * d;

    print_complex(a, b);
    printf(" ");
    print_complex(c, d);
    printf("\n");
    print_complex(a + c, b + d);
    printf("\n");
    print_complex(a - c, b - d);
    printf("\n");
    print_complex(a * c - b * d, b * c + a * d);
    printf("\n");
    print_complex((a * c + b * d) / denom, (b * c - a * d) / denom);
    printf("\n");

    return 0;
}
