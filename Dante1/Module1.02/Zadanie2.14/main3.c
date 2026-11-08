#include <stdio.h>

int read_next(float *min, float *max, float *sum, int *count)
{
    float x;

    if (scanf("%f", &x) != 1 || x == -1) {
        return 0;
    }

    if (*count == 0 || x < *min) {
        *min = x;
    }
    if (*count == 0 || x > *max) {
        *max = x;
    }

    *sum += x;
    (*count)++;

    return 1;
}

int main(void)
{
    float min = 0, max = 0, sum = 0;
    int count = 0;

    printf("Enter:\n");

    (void)(read_next(&min, &max, &sum, &count) &&
           read_next(&min, &max, &sum, &count) &&
           read_next(&min, &max, &sum, &count) &&
           read_next(&min, &max, &sum, &count) &&
           read_next(&min, &max, &sum, &count));

    if (count == 0) {
        printf("Error");
        return 0;
    }

    printf("%.2f\n%.2f\n%.2f", min, max, sum / count);
    return 0;
}
