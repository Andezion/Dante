#include <stdio.h>
#include <math.h>

int is_prime(int a);

int main()
{
    int data[10][10] = { 0 };

    int count = 0;

    printf("Enter number:\n");
    while (count < 100)
    {
        int value;

        int check = scanf("%i", &value);
        if (check != 1)
        {
            printf("Incorrect input\n");
            return 1;
        }

        if (is_prime(value) == 1)
        {
            int row = count / 10;
            int col = count % 10;

            *(*(data + row) + col) = value;
            count++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i % 3 == 0 && j % 3 == 0)
            {
                printf("%i ", *(*(data + i) + j));
            }
        }
    }

    return 0;
}

int is_prime(int a)
{
    if(a <= 1)
    {
        return 0;
    }

    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
