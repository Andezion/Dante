#include <stdlib.h>
#include "int_operations.h"

int add_int(int a, int b)
{
    return a + b;
}

int sub_int(int a, int b)
{
    return a - b;
}

int mul_int(int a, int b)
{
    return a * b;
}

int div_int(int a, int b)
{
    if(b == 0)
    {
        return 0;
    }
    return a / b;
}

int (*get_function(operations_t oper))(int, int)
{
    if(oper == op_add)
    {
        return add_int;
    }
    else if(oper == op_sub)
    {
        return sub_int;
    }
    else if(oper == op_mul)
    {
        return mul_int;
    }
    else if(oper == op_div)
    {
        return div_int;
    }
    else
    {
        return NULL;
    }
}
