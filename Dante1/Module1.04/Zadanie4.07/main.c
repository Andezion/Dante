#include <stdio.h>

int helper(int num)
{
    int counter = 0;

    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            counter++;
        }
    }

    if(num <= 0)
    {
        return 0;
    }
    if(num != 1)
    {
        if(counter <= 2)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 0;
}


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
        if(helper(data[i]) == 1)
        {
            printf("%i prime\n",data[i]);
        }
        else if(helper(data[i]) == 2)
        {
            printf("%i composite\n",data[i]);
        }
        else
        {
            printf("%i other\n",data[i]);
        }
    }

    return 0;
}
