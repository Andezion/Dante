#include <stdio.h>
#include <ctype.h>


int swap(int *a, int *b);

int main()
{
    int num1, num2;

    printf("Enter number: ");
    int check = scanf("%i %i",&num1, &num2);
    if(check != 2)
    {
        printf("Incorrect input");
        return 1;
    }

    swap(&num1, &num2);
    

    printf("%i %i",num1,num2);

    return 0;
}

int swap(int *a, int *b)
{
    if(a == NULL || b == NULL || a == b)
    {
        return 1;
    }

    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}
