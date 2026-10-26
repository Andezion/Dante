#include <stdio.h>
#include <limits.h>

int main() {
    printf("Enter:\n");

    int tab[100];

    int index = 0;
    int max = INT_MIN, min = INT_MAX;
    int sum = 0;

    while (index != 100) {
        if (scanf("%d", &tab[index]) != 1) {
            printf("Incorrect input\n");
            return 1;
        }

        if (tab[index] == -1) {
            break;
        }

        max = (max < tab[index]) ? tab[index] : max;
        min = (min > tab[index]) ? tab[index] : min;

        sum = sum + tab[index];

        index++;
    }

    printf("%d\n%d\n%d\n%.4f\n%d\n", index, min, max, (float) sum / index, sum);

    for (int i = 0; i < index; i++) {
        if (tab[i] == min) {
            printf("%d ", i);
        } 
    }
    printf("\n");

    for (int i = 0; i < index; i++) {
        if (tab[i] == max) {
            printf("%d ", i);
        } 
    }
    printf("\n");

    return 0;
}
