#include <stdio.h>

int main()
{
    double begin, in_one_month, end;
    int month;

    printf("Enter: ");

    int check1 = scanf("%lf", &begin);
    if (check1 != 1 || begin < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\nEnter: ");

    int check2 = scanf("%d", &month);
    if (check2 != 1 || month < 0)
    {
        printf("Incorrect input");
        return 1;
    }

    in_one_month = 0.01;

    for (int i = 0; i < month; i++)
    {
        begin = begin + begin * in_one_month;
    }

    end = begin;

    printf("\nResult: %.2lf\n", end);

    return 0;
}
