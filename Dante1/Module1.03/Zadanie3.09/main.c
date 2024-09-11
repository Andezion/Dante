#include <stdio.h>

int main()
{
    for(int i = -10; i <= 10; i++)
    {
        for(int j = -10; j <= 10; j++)
        {
            if((i - j) * (i + j) == i * i + j * j)
            {
                printf("%i %i\n",i,j);
            }
        }
    }

    return 0;
}
