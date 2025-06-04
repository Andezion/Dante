#include <stdio.h>

int is_prime(int a)
{
    int counter = 0;
    if(a == 0 || a == 1 || a < 0)
    {
        return 0;
    }
    for(int i = 1; i <= a; i++)
    {
        if(a % i == 0)
        {
            counter++;
        }
    }
    if(counter <= 2)
    {
        return 1;
    }
    return 0;
}


int main()
{
    int matrix[5][5];

    printf("Enter:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int error = scanf("%i", &matrix[i][j]);
            if(error != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int max_primes = 0;
    int count = 0;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            int prime_count = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (is_prime(matrix[i + x][j + y]))
                    {
                        prime_count++;
                    }
                }
            }

            if (prime_count > max_primes)
            {
                max_primes = prime_count;
                count = 1;
            }
            else if (prime_count == max_primes)
            {
                count++;
            }
        }
    }

    if (max_primes == 0)
    {
        printf("0");
    }
    else
    {
        printf("%d", count);
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                int prime_count = 0;

                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (is_prime(matrix[i + x][j + y]))
                        {
                            prime_count++;
                        }
                    }
                }

                if (prime_count == max_primes)
                {
                    printf("\n%i %i", i + 1, j + 1);
                }
            }
        }
    }

    return 0;
}
