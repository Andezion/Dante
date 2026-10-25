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
        printf("%d ", vec[i]);
    }
}

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (first == NULL || second == NULL || dest == NULL || size <= 0 || size2 <= 0 || size3 <= 0) {
        return -1;
    } 
    if ((size + size2) > size3) {
        return -2;
    }

    for (int i = 0; i < size; i++) {
        dest[i] = first[i];
    }
    for (int i = 0; i < size2; i++) {
        dest[size + i] = second[i];
    }

    return size + size2;
}

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (first == NULL || second == NULL || dest == NULL || size <= 0 || size2 <= 0 || size3 <= 0) {
        return -1;
    } 
    if ((size + size2) > size3) {
        return -2;
    }

    for (int i = 0; i < size2; i++) {
        dest[i] = second[i];
    }
    for (int i = 0; i < size; i++) {
        dest[size2 + i] = first[i];
    }

    return size + size2;
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (first == NULL || second == NULL || dest == NULL || size <= 0 || size2 <= 0 || size3 <= 0) {
        return -1;
    } 
    if ((size + size2) > size3) {
        return -2;
    }

    int min_size = (size < size2) ? size : size2;
    for (int i = 0; i < min_size; i++) {
        dest[2 * i] = first[i];
        dest[2 * i + 1] = second[i];
    }
    if (size > size2) {
        for (int i = min_size; i < size; i++) {
            dest[2 * min_size + (i - min_size)] = first[i];
        }
    } else {
        for (int i = min_size; i < size2; i++) {
            dest[2 * min_size + (i - min_size)] = second[i];
        }
    }

    return size + size2;
}

