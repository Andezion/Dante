#include <stdio.h>

int main(void)
{
    int num1, num2;
    char type = 0;

    printf("Enter numbers: ");
    int ok = scanf("%d %d", &num1, &num2) == 2
          && printf("Enter type: ")
          && scanf(" %c", &type) == 1;

    switch (ok * type)
    {
        case '+':
            printf("%d", num1 + num2);
            return 0;
        case '-':
            printf("%d", num1 - num2);
            return 0;
        case '*':
            printf("%d", num1 * num2);
            return 0;
        case '/':
            switch (num2)
            {
                case 0:
                    printf("Illegal operation");
                    return 2;
                default:
                    printf("%.2f", (float)num1 / num2);
                    return 0;
            }
        default:
            printf("Incorrect input");
            return 1;
    }
}
