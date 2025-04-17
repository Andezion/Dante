#ifndef NAPISY_COMPARATORS_H
#define NAPISY_COMPARATORS_H

typedef int(* func)(const int *, const int *, int);
int sort_rows(int **array, int height, int width, func types);
int comp_min(const int *array1, const int *array2, int number);
int comp_max(const int *array1, const int *array2, int number);
int comp_sum(const int *array1, const int *array2, int number);

#endif //NAPISY_COMPARATORS_H
