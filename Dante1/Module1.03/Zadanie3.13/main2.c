#include <stdio.h>
#include <stdbool.h>

int main()
{
    float temp1;
    float temp2 = 0;
    int iter = 0;

    while(true)
    {
        temp1 = 0;

        printf("Enter: ");
        if (scanf("%f", &temp1) != 1) {
            printf("Incorrect input\n");
            return 1;
        }

        if (temp1 == 0) {
            break;
        }

        if (iter != 0) {
            printf("%f\n", temp1 - temp2);
        }

        temp2 = temp1;
        iter = 1;
    }

    return 0;
}
