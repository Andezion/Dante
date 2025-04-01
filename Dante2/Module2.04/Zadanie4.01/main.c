#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *matrix = malloc(sizeof(int) * 100);
    if(!matrix)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    for(int i = 0; i < 100; i++)
    {
        *(matrix + i) = i;
    }
    for(int i = 0; i < 100; i++)
    {
        printf("%i ",*(matrix + i));
    }

    free(matrix);
    return 0;
}
