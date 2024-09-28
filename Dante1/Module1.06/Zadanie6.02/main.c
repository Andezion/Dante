#include <stdio.h>
#include <math.h>

int main()
{
    for(float i = 0; i < 2 * M_PI + M_PI / 100 ; i = i + M_PI / 100)
    {
        printf("%.4f %.4f\n",i,sinf(i));
    }

    return 0;
}
