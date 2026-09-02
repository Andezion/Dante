#include <stdio.h>

int main(void)
{
    char str[256];
    printf("Enter 10 numbers separated by spaces:\n");

    if (scanf("%255[^\n]", str) != 1)
    {
        printf("Wrong input\n");
        return 1;
    }

    int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    int offset = 0;
    int count = 0;

    count = sscanf(str, "%i %i %i %i %i %i %i %i %i %i %n",
                   &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &offset);

    if (count != 10 || str[offset] != '\0')
    {
        printf("Wrong input\n");
        return 1;
    }

    int sum = a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
    printf("Result is: %.4f\n", (float) sum / 10);

    return 0;
}
