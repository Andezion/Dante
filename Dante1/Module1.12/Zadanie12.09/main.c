#include <stdio.h>

int main()
{
    int a;

    int number;
    printf("Enter num: ");
    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    for (a = 0; a <= number; a++)
    {
        int p = 0;
        int suma = 0;
        while (suma < number)
        {
            suma = suma + a + p;
            p++;
        }

        if (suma == number)
        {
            printf("\n%i %i", a, p);
            break;
        }
    }

    return 0;
}
