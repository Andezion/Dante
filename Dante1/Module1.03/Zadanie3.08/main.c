#include <stdio.h>

int main()
{
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            printf("%i * %i = %i\n",i,j,i * j);
        }
        printf("\n");
    }

    return 0;
}
