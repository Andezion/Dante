#ifndef MAIN_C_FUNCTIONS_H
#define MAIN_C_FUNCTIONS_H

enum type {ALL_ODD, ALL_EVEN, MIX};

int all_even(int number);
int all_odd(int number);
int get_next_number(const int *tab, int size, enum type t);

#endif //MAIN_C_FUNCTIONS_H
