#include <stdio.h>
#include <math.h>

int main() {
    printf("Enter:\n");
    float num1, num2, num3, num4, num5;
    if (scanf("%f %f %f %f %f",&num1, &num2, &num3, &num4, &num5) != 5) {
        printf("Incorrect input");
        return 1;
    }

    printf("%f\n%f\n%.2f\n", 
                                    fmin(num1, fmin(num2, fmin(num3, fmin(num4, num5)))),
                                    fmax(num1, fmax(num2, fmax(num3, fmax(num4, num5)))),
                                    (num1 + num2 + num3 + num4 + num5) / 5
                                );

    return 0;
}
