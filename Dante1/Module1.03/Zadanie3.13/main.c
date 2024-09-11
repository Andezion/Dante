#include <stdio.h>

int main()
{
    float temp1;
    float temp2 = 0;
    int iter = 0;

    while(1)
    {
        temp1 = 0;

        printf("Enter: ");
        int check = scanf("%f", &temp1);

        if (check != 1)
        {
            printf("Incorrect input\n");
            return 1;
        }

        if (temp1 == 0)
        {
            break;
        }

        if (iter != 0)
        {
            float diff = temp1 - temp2;
            printf("%f\n", diff);
        }

        temp2 = temp1;
        iter = 1;
    }

    return 0;
}
