#include <stdio.h>

int main()
{
    double num1 = 6.0;
    int num2 = 2;
    int z = (int)num1 * num2;
    int c = (int)num1 + num2;
    int v = (int)num1 - num2;
    printf("%i %i\n", (int)num1, num2);

    printf("%i\n",z);
    printf("%.2f\n", num1 / num2);
    printf("%i\n",c);
    printf("%i",v);
    return 0;
}
