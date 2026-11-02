#include <stdio.h>

int main()
{
    float number;
    printf("Enter number: ");

    int check = scanf("%f",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%f\n%f",number, number * 10);
    return 0;
}
