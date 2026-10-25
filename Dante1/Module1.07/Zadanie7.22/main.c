#include <stdio.h>

#include "vector_utils.h"

#define MAX_SIZE 50

int main(void) {
    printf("Enter vector1: ");

    int vec1[MAX_SIZE];
    int size1 = read_vector(vec1, MAX_SIZE, 0);
    if (size1 == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size1 < 1) {
        printf("Not enough data available\n");
        return 2;
    }

    while (getchar() != '\n'); 

    printf("\n");
    printf("Enter vector2: ");

    int vec2[MAX_SIZE];
    int size2 = read_vector(vec2, MAX_SIZE, 0);
    if (size2 == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size1 < 1) {
        printf("Not enough data available\n");
        return 2;
    }

    while (getchar() != '\n'); 

    if (size1 == 0) {
        printf("Not enough data available\n");
        return 2;
    }

    if (size2 == 0) {
        printf("Not enough data available\n");
        return 2;
    }

    display_vector(vec1, size1);
    printf("\n");
    display_vector(vec2, size2);
    printf("\n");

    if (size1 + size2 > MAX_SIZE) {
        printf("Output buffer is too small\n");
        return 0;
    }

    int dest[100];
    int size = concat_begin(vec1, size1, vec2, size2, dest, size1 + size2);
    display_vector(dest, size);

    printf("\n");

    size = concat_end(vec1, size1, vec2, size2, dest, size1 + size2);
    display_vector(dest, size);

    printf("\n");

    size = concat_zip(vec1, size1, vec2, size2, dest, size1 + size2);
    display_vector(dest, size);

    printf("\n");

    return 0;
}