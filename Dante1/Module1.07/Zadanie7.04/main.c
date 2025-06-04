#include <stdio.h>

int sign(int value);

int main()
{
    int input;
    printf("Enter number: ");

    int check = scanf("%i", &input);
    while(check != 1)
    {
        printf("Incorrect input\n");
        return 1;

    }

    int result = sign(input);

    printf("%s\n", (result == 0) ? "zero" : ((result == 1) ? "positive" : "negative"));

    return 0;
}

int sign(int value)
{
    return (value > 0) - (value < 0);
}
