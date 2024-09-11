#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int number;
    while(1)
    {
        number = -1000 + rand() % (2001);
        if(100 <= number && number <= 200)
        {
            break;
        }
        printf("%i\n",number);
    }



    return 0;
}
