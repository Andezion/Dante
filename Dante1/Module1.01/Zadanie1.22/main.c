#include <stdio.h>

int main()
{
    float number;

    printf("Enter number: ");
    scanf("%f",&number);

    int num;
    printf("Enter num: ");
    scanf("%i",&num);

    printf("%.*f",num,number);

    return 0;
}
