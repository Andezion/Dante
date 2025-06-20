#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    printf("Enter: ");
    int check = scanf("%i",&n);
    if(check != 1 || n < 0 || n > 100000)
    {
        printf("\nIncorrect input");
        return 1;
    }

    printf("\n");

    if(n < 20)
    {
        printf("\nNothing to show");
        return 0;
    }
    int new = n / 10;

    int counter = 0;
    while(new != 0)
    {
        new = new / 10;
        counter++;
    }

    int num = (int)pow(10, counter);
    //printf("\n%i\n%i\n",num,num/10);

    if (n > 1000)
    {

        if(n < 1010)
        {
            //int count = 0;
            for(int i = 10; i < 100; i++)
            {
                printf("%i + %i = %i\n",n - i, i, n);
                //count++;
            }
            //printf("%i\n",count);
            return 0;
        }
        if(n < 10100)
        {
            //int count = 0;
            for(int i = 100; i < 1000; i++)
            {
                printf("%i + %i = %i\n",n - i, i, n);
                //count++;
            }
            //printf("%i\n",count);
            return 0;
        }
        if(n == 100000)
        {
            //int count = 0;
            for(int i = 1000; i < 10000; i++)
            {
                printf("%i + %i = %i\n",n - i, i, n);
                //count++;
            }
            //printf("%i\n",count);
            return 0;
        }
        //num = num / 10;
        for(int i = num / 10; i < num; i++)
        {
            printf("%i + %i = %i\n",n - i, i, n);
        }
    }
    else
    {
        //int count = 0;
        for(int i = num / 10; i < num; i++)
        {
            if(n >= 100 && n - i < 100)
            {
                break;
            }
            printf("%i + %i = %i\n",n - i, i, n);
            //count++;
        }
        //printf("%i\n",count);
    }


    return 0;
}
