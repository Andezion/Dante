#include <stdio.h>

int main()
{
    int input;
    int result[11] = {0 };

    printf("Enter: ");

    while (1)
    {
        int check = scanf("%i", &input);
        if (check != 1)
        {
            printf("Incorrect input\n");
            return 1;
        }

        if (input == -1)
        {
            break;
        }

        if (input >= 0 && input <= 10)
        {
            result[input]++;
        }
    }

    for (int i = 0; i <= 10; i++)
    {
        printf("%i - %i\n", i, result[i]);
    }

    return 0;
}
