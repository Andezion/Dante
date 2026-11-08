#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    printf("Enter two numbers:\n");

    switch ((int) (scanf("%d",&a) == 1 && scanf("%d",&b) == 1))
    {
        case 1:
            printf("%d\n%d", (int) ((a + b + sqrt((a - b) * (a - b))) / 2), (int) ((a + b - sqrt((a - b) * (a - b))) / 2));
            return 0;
        default:
            printf("Incorrect input");
            return 1;
    }
}
