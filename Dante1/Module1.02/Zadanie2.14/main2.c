#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2, num3, num4, num5;

    printf("Enter:\n");

    if (scanf("%f", &num1) != 1 || num1 == -1)
    {
        printf("Error");
        return 0;
    }

    if (scanf("%f", &num2) != 1 || num2 == -1) {
        printf("%.2f\n%.2f\n%.2f", num1, num1, num1);
        return 0;
    }

    if (scanf("%f", &num3) != 1 || num3 == -1) {
        float max = fmax(num1, num2);
        float min = fmin(num1, num2);

        printf("%.2f\n%.2f\n%.2f", min, max, (num1 + num2) / 2);
        return 0;
    }

    if (scanf("%f", &num4) != 1 || num4 == -1) {
        float max = fmax(num1, fmax(num2, num3));
        float min = fmin(num1, fmin(num2, num3));

        printf("%.2f\n%.2f\n%.2f", min, max, (num1 + num2 + num3) / 3);
        return 0;
    }

    if (scanf("%f", &num5) != 1 || num5 == -1) {
        float max = fmax(num1, fmax(num2, fmax(num3, num4)));
        float min = fmin(num1, fmin(num2, fmin(num3, num4)));

        printf("%.2f\n%.2f\n%.2f", min, max, (num1 + num2 + num3 + num4) / 4);
        return 0;
    }

    float max = fmax(num1, fmax(num2, fmax(num3, fmax(num4, num5))));
    float min = fmin(num1, fmin(num2, fmin(num3, fmin(num4, num5))));

    printf("\n%.2f\n%.2f\n%.2f",min, max, (num1 + num2 + num3 + num4 + num5) / 5);

    return 0;
}
