#include <stdio.h>

int main()
{
    int num;
    char *data[] = {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec"};
    printf("Enter: ");

    int check = scanf("%i",&num);

    printf("\n");

    int try = (check == 1) && (num >= 0) && (num <= 10);
    switch(try)
    {
        case 1:
            printf("%s", data[num]);
            return 0;
        default:
            printf("Incorrect input");
            return 1;
    }
}
