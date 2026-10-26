#include <stdio.h>

#include "vector_utils.h"
#include "bubble_sort.h"
#include "types_utils.h"

int main() {
    printf("Enter vector: ");

    int tab[50];
    int size = read_vector(tab, 50, 0);
    if (size == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size < 1) {
        printf("Not enough data available\n");
        return 3;
    }
    if (size == 50) {
        scanf("%*[^\n]");
        scanf("%*c");
    }

    printf("Enter dir: ");
    int dir;
    if (scanf("%d", &dir) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (dir != ASCENDING && dir != DESCENDING) {
        printf("Incorrect input data\n");
        return 2;
    }

    if (bubble_sort_rec(tab, size, dir) == 1) {
        printf("Incorrect input\n");
        return 1;
    }

    display_vector(tab, size);

    return 0;
}