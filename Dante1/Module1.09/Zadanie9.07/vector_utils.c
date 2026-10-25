#include "vector_utils.h"

int read_vector(int vec[], int size, int stop_value) {
    if (vec == NULL || size <= 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &vec[i]) != 1) {
            return -2;
        }
        if (vec[i] == stop_value) {
            return i;
        }
    }
    return size;
}

void display_vector(const int vec[], int size) {
    if (vec == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", vec[i]);
    }
    printf("\n");
}