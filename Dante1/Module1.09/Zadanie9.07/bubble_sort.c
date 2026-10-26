#include "bubble_sort.h"

int bubble_pass_asc_rec(int tab[], int size, int i) {
    if (i == size - 1) {
        return 0;
    }

    int swapped = 0;
    if (tab[i] > tab[i + 1]) {
        int temp = tab[i];
        tab[i] = tab[i + 1];
        tab[i + 1] = temp;
        swapped = 1;
    }
    int next_swapped = bubble_pass_asc_rec(tab, size, i + 1);
    return swapped || next_swapped;
}

int bubble_sort_asc_rec(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }

    if (size <= 1) {
        return 0; 
    }

    int swapped = bubble_pass_asc_rec(tab, size, 0);
    if (!swapped) {
        return 0;
    }

    display_vector(tab, size);

    bubble_sort_asc_rec(tab, size - 1);

    return 0; 
}

int bubble_pass_desc_rec(int tab[], int size, int i) {
    if (i == size - 1) {
        return 0;
    }

    int swapped = 0;
    if (tab[i] < tab[i + 1]) {
        int temp = tab[i];
        tab[i] = tab[i + 1];
        tab[i + 1] = temp;
        swapped = 1;
    }
    int next_swapped = bubble_pass_desc_rec(tab, size, i + 1);
    return swapped || next_swapped;
}

int bubble_sort_desc_rec(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }

    if (size <= 1) {
        return 0; 
    }

    int swapped = bubble_pass_desc_rec(tab, size, 0);
    if (!swapped) {
        return 0;
    }

    display_vector(tab, size);

    bubble_sort_desc_rec(tab, size - 1);

    return 0;
}


int bubble_sort_rec(int tab[], int size, enum direction dir) {
    if (tab == NULL || size <= 0 || (dir != ASCENDING && dir != DESCENDING)) {
        return 1; 
    }

    if (dir == ASCENDING) {
        return bubble_sort_asc_rec(tab, size);
    } 
    return bubble_sort_desc_rec(tab, size);
}