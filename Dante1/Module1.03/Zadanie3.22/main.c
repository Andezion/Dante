#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    for(int i = 0; i < 101; i++)
    {
        if(i >= 10 && i < 15)
        {
            printf("*%i\n",i);
        }
        else if(i >= 40 && i <= 60)
        {
            printf("*%i\n",i);
        }
        else if(i > 70 && i < 80)
        {
            printf("*%i\n",i);
        }
        else
        {
            printf("%i\n",i);
        }
    }
    return 0;
}
