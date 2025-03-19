#include <stdio.h>

struct date_t
{
    int day;
    int month;
    int year;
};

struct date_t* set_date(struct date_t* d, int day, int month, int year, int *err_code);
struct date_t* read(struct date_t* d, int *err_code);
void show(const struct date_t* d);
int validate(const struct date_t* d);

int main()
{
    struct date_t d;
    int err_code;

    if(!read(&d, &err_code))
    {
        printf("Incorrect input");
        return 1;
    }

    struct date_t *result = set_date(&d, d.day, d.month, d.year, &err_code);
    if(result == NULL)
    {
        printf("Incorrect input");
        return 1;
    }

    int res = validate(&d);
    if(res == 0 || res == -1)
    {
        printf("Incorrect");
    }
    else
    {
        show(&d);
        printf("Correct");
    }

    return 0;
}

struct date_t* set_date(struct date_t* d, int day, int month, int year, int *err_code)
{
    if(d == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    d->day = day;
    d->month = month;
    d->year = year;

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return d;
}

int validate(const struct date_t* d)
{
    if(d == NULL)
    {
        return -1;
    }

    if(d->day == 0 || d->month == 0 || d->year < 0 || d->day > 31 || d->day < 0 || d->month > 12 || d->month < 0)
    {
        return 0;
    }

    if(d->month == 1 && d->day != 31)
    {
        return 0;
    }
    if(d->month == 2)
    {
        if ((d->year % 4 == 0 && d->year % 100 != 0) || (d->year % 400 == 0))
        {
            if(d->day > 29)
            {
                return 0;
            }
        }
        else
        {
            if(d->day > 28)
            {
                return 0;
            }
        }
    }
    if(d->month == 3 && d->day > 31)
    {
        return 0;
    }
    if(d->month == 4 && d->day > 30)
    {
        return 0;
    }
    if(d->month == 5 && d->day > 31)
    {
        return 0;
    }
    if(d->month == 6 && d->day > 30)
    {
        return 0;
    }
    if(d->month == 7 && d->day > 31)
    {
        return 0;
    }
    if(d->month == 8 && d->day > 31)
    {
        return 0;
    }
    if(d->month == 9 && d->day > 30)
    {
        return 0;
    }
    if(d->month == 10 && d->day > 31)
    {
        return 0;
    }
    if(d->month == 11 && d->day > 30)
    {
        return 0;
    }
    if(d->month == 12 && d->day > 31)
    {
        return 0;
    }

    return 1;
}

struct date_t* read(struct date_t* d, int *err_code)
{
    if(d == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    printf("Enter: ");
    int check = scanf("%i-%i-%i",&d->day,&d->month,&d->year);
    if(check != 3)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return NULL;
    }

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return d;
}

void show(const struct date_t* d)
{
    if(d == NULL)
    {
        return;
    }

    if(d->day < 10)
    {
        if(d->month < 10)
        {
            if(d->year < 1000)
            {
                printf("0%i-0%i-0%i\n",d->day,d->month,d->year);
            }
            if(d->year >= 1000)
            {
                printf("0%i-0%i-%i\n",d->day,d->month,d->year);
            }
        }
        else
        {
            if(d->year < 1000)
            {
                printf("0%i-%i-0%i\n",d->day,d->month,d->year);
            }
            if(d->year >= 1000)
            {
                printf("0%i-%i-%i\n",d->day,d->month,d->year);
            }
        }
    }
    else
    {
        if(d->month < 10)
        {
            if(d->year < 1000)
            {
                printf("%i-0%i-0%i\n",d->day,d->month,d->year);
            }
            if(d->year >= 1000)
            {
                printf("%i-0%i-%i\n",d->day,d->month,d->year);
            }
        }
        else
        {
            if(d->year < 1000)
            {
                printf("%i-%i-0%i\n",d->day,d->month,d->year);
            }
            if(d->year >= 1000)
            {
                printf("%i-%i-%i\n",d->day,d->month,d->year);
            }
        }
    }
}
