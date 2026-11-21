#include <stdio.h>
#include <math.h>

float distance(int x1, int y1, int x2, int y2);
float perimeter(float a, float b, float c);
float area(float a, float b, float c);

int main() {
    int x1, y1;
    printf("Enter first point: ");
    if (scanf("(%d, %d)", &x1, &y1) != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    while(getchar() != '\n');

    int x2, y2;
    printf("Enter second point: ");
    if (scanf("(%d, %d)", &x2, &y2) != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    while(getchar() != '\n');

    int x3, y3;
    printf("Enter third point: ");
    if (scanf("(%d, %d)", &x3, &y3) != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    float s = area(a, b, c);
    if (s < 0) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("%.2f\n", s);

    return 0;
}

float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float perimeter(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        return -1.0;
    }
    return a + b + c;
}

float area(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        return -1.0;
    }
    float p = perimeter(a, b, c);
    float s = p / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
