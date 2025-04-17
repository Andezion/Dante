#ifndef PAST6MODULE_INT_OPERATIONS_H
#define PAST6MODULE_INT_OPERATIONS_H

int add_int(int a, int b);
int sub_int(int a, int b);
int mul_int(int a, int b);
int div_int(int a, int b);

int calculate(int a, int b, int (*type)(int, int));

#endif //PAST6MODULE_INT_OPERATIONS_H
