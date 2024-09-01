#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    int b;
    printf("Enter two numbers:\n");
    int a1 = scanf("%i",&a);
    int b1 = scanf("%i",&b);
    int x = ((a + b + sqrt((a - b) * (a - b))) / 2);
    int y = ((a + b - sqrt((a - b) * (a - b))) / 2);

    switch (a1)
    {
        case 1:
            switch (b1)
            {
                case 1:
                    printf("%i\n",x);
                    printf("%i\n",y);
                    return 0;
                default:
                    printf("Incorrect input");
                    return 1;
            }
        default:
            printf("Incorrect input");
            return 1;
    }
}
