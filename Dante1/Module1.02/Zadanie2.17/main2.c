#include <stdio.h>

int main()
{
    float number;

    printf("Enter: ");
    if (scanf("%f",&number) != 1) {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");
    if(number > 5) {
        printf("%f",(0.5 * number - 2) * (2 - 0.75 * number));
    } else if(number < -5) {
        printf("%f",(number + 5) * (number + 5) - 10);
    } else {
        printf("%f",2 * number * number + 3 * number - 1);
    }

    return 0;
}
