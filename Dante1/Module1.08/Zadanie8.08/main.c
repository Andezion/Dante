#include <stdio.h>
#include <stdlib.h>

int even_odd(int s, int n);

int main()
{
    int number, type;

    printf("Enter number: ");
    int check = scanf("%i",&number);
    if(check != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");

    printf("Enter type: ");
    int check2 = scanf("%i",&type);
    if(check2 != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if(type < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    int result = even_odd(number,type);
    if(result == -1)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("\n%i", result);
    return 0;
}

int even_odd(int s, int n)
{
    if(n < 0)
    {
        return -1;
    }
   if(n == 0)
   {
       return s;
   }

   int temp = abs(s);
   if(temp % 2 == 1)
   {
       return even_odd(3 * s + 1,n - 1);
   }
   return even_odd(s / 2, n - 1);
}
