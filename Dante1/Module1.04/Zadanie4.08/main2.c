#include <stdio.h>
#include <limits.h>

int main() {
    printf("Enter 10 numbers:\n");

    int tab[10];

    int sum = 0;
    int max = INT_MIN, min = INT_MAX;
    
    for (int i = 0; i < 10; i = i + 2) {
        if (scanf("%d %d", &tab[i], &tab[i + 1]) != 2) {
            printf("Input data type error\n");
            return 1;
        }

        max = (max < tab[i]) ? tab[i] : max;
        max = (max < tab[i + 1]) ? tab[i + 1] : max;
        min = (min > tab[i]) ? tab[i] : min;
        min = (min > tab[i + 1]) ? tab[i + 1] : min;
        sum = sum + tab[i] + tab[i + 1];
    }

    printf("%.4f\n%d\n%d\n", (float) sum / 10.0, max, min);

    return 0;
}
