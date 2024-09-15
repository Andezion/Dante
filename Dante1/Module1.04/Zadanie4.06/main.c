#include <stdio.h>

int main()
{
    int data[10];
    printf("Enter numbers:\n");

    for(int i = 0; i < 10; i++)
    {
        int check = scanf("%i %i",&data[i], &data[i + 1]);
        if(check != 2)
        {
            printf("Input data type error\n");
            return 1;
        }
        i++;
    }

    for(int i = 0; i < 10; i++)
    {
        if(data[i] % 2 == 0)
        {
            printf("%i Even\n",data[i]);
        }
        else
        {
            printf("%i Odd\n",data[i]);
        }
    }

    return 0;
}
