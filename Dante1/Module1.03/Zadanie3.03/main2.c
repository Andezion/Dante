#include <stdio.h>

int main()
{
    int month;
    double begin;
    
    printf("Enter: ");

    if (scanf("%lf", &begin) != 1 || begin < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");

    if (scanf("%d", &month) != 1 || month < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    for (int i = 0; i < month; i++)
    {
        begin = begin + begin * 0.01;
    }

    printf("\nResult: %.2lf\n", begin);

    return 0;
}
