#include <stdio.h>

int main()
{
    int day;
    char *data[] = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};

    printf("Enter your day:");
    int check = scanf("%d", &day);

    switch ((int) ((check == 1) && (day >= 1 && day <= 7)))
    {
        case 1:
            printf("%s", data[day - 1]);
            break;
        default:
            printf("Incorrect input");
            return 1;
    }
    return 0;

}
