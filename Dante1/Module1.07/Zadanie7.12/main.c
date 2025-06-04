#include <stdio.h>

int is_prime(int a);

int is_twin(int a, int b)
{
    return is_prime(a) && is_prime(b) && ((a - b == 2) || (b - a) == 2);
}

int main()
{
    int a;
    printf("Enter: ");

    int check1 = scanf("%i",&a);
    if(check1 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    int b;
    printf("\nEnter: ");

    int check2 = scanf("%i",&b);
    if(check2 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    if(b + 2 <= a)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\n");
    int pointer = 0;
    for(int i = a; i <= b - 2; i++)
    {
        if(is_twin(i, i + 2))
        {
            printf("%i, %i\n",i, i + 2);
            pointer = 1;
        }
    }
    if(pointer == 0)
    {
        printf("\nNothing to show\n");
    }

    return 0;
}

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
