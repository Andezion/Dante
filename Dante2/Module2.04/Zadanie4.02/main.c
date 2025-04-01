#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float *data = malloc((sizeof(float)));
    if(!data)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    *data = 3.14159265359f;
    printf("%f %p",*(data), (void *)data);

    free(data);
    return 0;
}
