#ifndef PAST6MODULE_COMPARATORS_H
#define PAST6MODULE_COMPARATORS_H

int comp_int(int a, int b);
int comp_int_abs(int a, int b);
int comp_int_length(int a, int b);
int comp_int_digits_sum(int a, int b);

int sort_int(int *array, int size, int(*func)(int, int));

#endif //PAST6MODULE_COMPARATORS_H
