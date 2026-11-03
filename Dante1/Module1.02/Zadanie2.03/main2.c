#include <stdio.h>

static int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static int is_valid_date(int day, int month, int year)
{
    static const int days_in_month[12] = {31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};

    if (year < 1000 || month < 1 || month > 12 || day < 1)
        return 0;

    int max_day = days_in_month[month - 1];
    if (month == 2 && is_leap_year(year))
        max_day = 29;

    return day <= max_day;
}

int main(void)
{
    int day, month, year;

    printf("Enter: ");
    if (scanf("%2d-%2d-%4d", &day, &month, &year) != 3)
    {
        printf("Incorrect input");
        return 1;
    }

    printf(is_valid_date(day, month, year) ? "correct" : "incorrect");
    return 0;
}
