#include <stdio.h>

void print_stars(int counter)
{
    if(0 != counter)
    {
        printf("* ");
        print_stars(counter - 1);
    }
}

void rectangular_triangle(int n)
{
    if(n < 0)
    {
        return;
    }
    if(0 != n)
    {
        rectangular_triangle(n - 1);
        print_stars(n);
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter: ");

    int check = scanf("%i",&n);
    if(check != 1)
    {
        printf("\nIncorrect input");
        return 1;
    }
    if(n <= 0)
    {
        printf("\nIncorrect input data");
        return 2;
    }

    printf("\n");
    rectangular_triangle(n);
    return 0;
}
