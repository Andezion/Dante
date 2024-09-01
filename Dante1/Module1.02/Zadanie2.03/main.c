#include <stdio.h>

int is_leap_year(unsigned year)
{
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

int main ()
{
    int error;

    int day, month, year;
    printf("Enter: ");
    error = scanf("%2d-%2d-%4d" , &day, &month, &year);
    if (error != 3)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("\n");
    if ((month == 4 && day == 31) || (month == 6 && day == 31) || (month == 9 && day == 31)
        || (month == 11 && day == 31) || (month == 2 && day > 28 && !is_leap_year(year)) ||
            1 > day || day > 31 || 1 > month || month > 12 || 999 > year)
    {
        printf("incorrect");
    }
    else
    {
        printf("correct");
    }

    return 0;
}
