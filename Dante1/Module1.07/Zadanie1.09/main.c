#include <stdio.h>

float poly(float);

int main(void)
{
    float number;
    printf("Enter float: ");
    int check = scanf("%f",&number);
    if(check != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Result is: %.2f",poly(number));
    return 0;
}

float poly(float num)
{
    return 5 * num * num + 12.55 * num + 0.75;
}
