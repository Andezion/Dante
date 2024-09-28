#include <stdio.h>

int main()
{
    int data[11][11];

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            data[i][j] = i * j;
            printf("%4i ",data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
