#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    float temp;
    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0;

    printf("Enter:\n");

    int counter = 0;
    while (true) {
        if (scanf("%f", &temp) != 1) {
            printf("Incorrect input");
            return 1;
        }

        if(temp == -1) {
            break;
        }

        max = fmax(max, temp);
        min = fmin(min, temp);

        sum = sum + temp;
        counter++;
    }

    printf("Min: %.2f\nMax: %.2f\nAverage: %.2f", min, max, sum / (float)counter);

    return 0;
}
