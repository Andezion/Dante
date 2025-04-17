#ifndef PAST6MODULE_INT_OPERATIONS_H
#define PAST6MODULE_INT_OPERATIONS_H

typedef enum {op_add = 0, op_sub, op_div, op_mul} operations_t;

int add_int(int a, int b);
int sub_int(int a, int b);
int mul_int(int a, int b);
int div_int(int a, int b);

int (*get_function(operations_t oper))(int a, int b);

#endif //PAST6MODULE_INT_OPERATIONS_H
