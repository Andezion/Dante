#include <stdio.h>

int main()
{
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%i %i %i %i %i %i %i %i %i %i %i\n",data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10]);
    for(int i = 0; i < 11; i++)
    {
        printf("%i\n",data[i]);
    }
    return 0;
}
