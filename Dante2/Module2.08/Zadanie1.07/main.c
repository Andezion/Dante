#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

struct point_t
{
    int x;
    int y;
};

int my_printf(char *txt, ...);
int my_scanf(char *txt, ...);

int main()
{
    int error;

    int number;
    my_printf("Hello guys!");

    my_printf("\nEnter: ");
    error = my_scanf("%d",&number);
    if(error != 1)
    {
        return 1;
    }

    my_printf("\nYour number is: %d",number);

    struct point_t a = {-627, -912};
    my_printf("\n%p",a);

    return 0;
}

int my_printf(char *txt, ...)
{
    int iterator = 0;
    int variable = 0;
    int error;

    va_list begin;
    va_start(begin, txt);

    for (; *(txt + iterator) != '\0';)
    {
        if (*(txt + iterator) == '%')
        {
            iterator++;

            if (*(txt + iterator) == 'd')
            {
                error = va_arg(begin, int);
                if (error == 0)
                {
                    variable++;

                    iterator++;

                    putchar('0');

                    continue;
                }

                int some_shit = error;

                int little_number = 0;

                int that_is_what_it_is = 0;

                if (some_shit < 0)
                {
                    putchar('-');

                    some_shit = some_shit * -1;

                    variable = variable + 1;
                }

                if(some_shit / 10 > 0)
                {
                    that_is_what_it_is = that_is_what_it_is + some_shit % 10;

                    some_shit = some_shit / 10;

                    little_number = little_number + 1;

                    while (some_shit >= 10)
                    {
                        that_is_what_it_is = that_is_what_it_is * 10;

                        that_is_what_it_is = that_is_what_it_is + some_shit % 10;

                        some_shit = some_shit / 10;

                        little_number = little_number + 1;
                    }
                    variable = variable + little_number;
                }

                variable = variable + 1;

                putchar(some_shit % 10 + '0');

                int j = 0;
                while(j < little_number)
                {
                    putchar(that_is_what_it_is % 10 + '0');

                    that_is_what_it_is = that_is_what_it_is / 10;

                    j++;
                }
            }
            else if (*(txt + iterator) == 's')
            {
                char *pointer;
                pointer = va_arg(begin, char*);

                int summator;

                summator = 0;

                for (; *(pointer + summator) != '\0';)
                {
                    putchar(*(pointer + summator));

                    summator = summator + 1;
                }
                variable = variable + summator;
            }
            else if (*(txt + iterator) == 'f')
            {
                double result;
                result = va_arg(begin, double);

                int nice_iterator = (int) result;

                int point_on = nice_iterator;

                int this_is_helper = 0;

                int helper_to_count = 0;

                if (nice_iterator < 0)
                {
                    putchar('-');

                    nice_iterator = nice_iterator * -1;

                    variable = variable + 1;

                }
                if (nice_iterator != 0)
                {
                    if(nice_iterator / 10 > 0)
                    {
                        this_is_helper = this_is_helper + nice_iterator % 10;

                        nice_iterator = nice_iterator / 10;

                        helper_to_count = helper_to_count + 1;

                        for (; nice_iterator >= 10;)
                        {
                            this_is_helper = this_is_helper * 10;

                            this_is_helper = this_is_helper + nice_iterator % 10;

                            nice_iterator = nice_iterator / 10;

                            helper_to_count = helper_to_count + 1;
                        }
                        variable = variable + helper_to_count;
                    }
                    variable = variable + 1;

                    putchar(nice_iterator % 10 + '0');

                    for (int j = 0; j < helper_to_count; j++)
                    {
                        putchar(this_is_helper % 10 + '0');
                        this_is_helper = this_is_helper / 10;
                    }
                }
                else
                {
                    putchar('0');
                    variable = variable + 1;
                }

                putchar('.');
                variable = variable + 1;
                result = result - (double) point_on;

                if (result < 0)
                {
                    result = result * -1;
                }
                for(int j = 0; j < 5; j++)
                {
                    putchar((((int)(result = result * 10)) % 10) + '0');

                    variable++;
                }
            }
            else if (*(txt + iterator) == 'p')
            {
                struct point_t test;
                test = va_arg(begin, struct point_t);

                putchar('(');

                variable = variable + 1;

                int let_it_be = test.x;

                int little_pointer = 0;

                int please_work = 0;

                if (let_it_be < 0)
                {
                    putchar('-');

                    let_it_be = let_it_be * -1;

                    variable = variable + 1;

                }

                if (let_it_be != 0)
                {
                    if(let_it_be / 10 > 0)
                    {
                        little_pointer = little_pointer + let_it_be % 10;

                        let_it_be = let_it_be / 10;

                        please_work = please_work + 1;

                        while (let_it_be >= 10)
                        {
                            little_pointer = little_pointer * 10;

                            little_pointer = little_pointer + let_it_be % 10;

                            let_it_be = let_it_be / 10;

                            please_work = please_work + 1;
                        }
                        variable = variable + please_work;
                    }

                    variable = variable + 1;

                    putchar(let_it_be % 10 + '0');

                    for (int j = 0; j < please_work; ++j)
                    {
                        putchar(little_pointer % 10 + '0');
                        little_pointer = little_pointer / 10;
                    }
                }
                else
                {
                    putchar('0');
                    variable = variable + 1;
                }

                putchar(' ');

                variable = variable + 1;

                let_it_be = test.y;

                if (let_it_be != 0)
                {
                    little_pointer = 0;

                    please_work = 0;

                    if (let_it_be < 0)
                    {
                        putchar('-');

                        let_it_be = let_it_be * -1;

                        variable = variable + 1;
                    }
                    if(let_it_be / 10 > 0)
                    {
                        little_pointer = little_pointer + let_it_be % 10;

                        let_it_be = let_it_be / 10;

                        please_work = please_work + 1;

                        while (let_it_be >= 10)
                        {
                            little_pointer = little_pointer * 10;

                            little_pointer = little_pointer + let_it_be % 10;

                            let_it_be = let_it_be / 10;

                            please_work = please_work + 1;
                        }
                        variable = variable + please_work;
                    }

                    variable = variable + 1;

                    putchar(let_it_be % 10 + '0');
                    for (int j = 0; j < please_work; j++)
                    {
                        putchar(little_pointer % 10 + '0');

                        little_pointer = little_pointer / 10;
                    }
                }
                else
                {
                    putchar('0');
                    variable = variable + 1;
                }
                variable = variable + 1;
                putchar(')');
            }
            else
            {
                putchar(*(txt + iterator));
                variable = variable + 1;
            }
        }
        else
        {
            putchar(*(txt + iterator));
            variable = variable + 1;
        }
        iterator = iterator + 1;
    }

    va_end(begin);
    return variable;
}

int my_scanf(char *txt, ...)
{
    int iterator = 0;
    int error_key = 0;

    va_list begin;
    va_start(begin, txt);

    int little_pointer = 1;
    char letter_to_read;

    for(; *(txt + iterator) != '\0';)
    {
        if(little_pointer)
        {
            letter_to_read = (char) getchar();
        }

        if(*(txt + iterator) == '%')
        {
            iterator = iterator + 1;

            if(*(txt + iterator) == 'd')
            {
                int *resulted;
                resulted = va_arg(begin, int *);

                int some_shit = 0;

                int helper_to_read = 0;

                int easy_to_use = 0;

                little_pointer = 1;

                for(; isdigit(letter_to_read) || letter_to_read == '-';)
                {
                    if(letter_to_read == '-')
                    {
                        if(easy_to_use != 0)
                        {
                            return error_key;
                        }

                        some_shit = 1;

                        letter_to_read = (char) getchar();

                        continue;
                    }

                    helper_to_read = helper_to_read + letter_to_read - '0';

                    easy_to_use = easy_to_use + 1;

                    letter_to_read = (char) getchar();

                    if(!isdigit(letter_to_read))
                    {
                        little_pointer = 0;

                        break;
                    }
                    helper_to_read = helper_to_read * 10;
                }

                if(easy_to_use == 0)
                {
                    return error_key;
                }

                if(some_shit)
                {
                    helper_to_read = helper_to_read * -1;
                }

                *resulted = helper_to_read;
                error_key = error_key + 1;
            }
            else if(*(txt + iterator) == 'f')
            {
                double *taker_of_some;
                taker_of_some = va_arg(begin, double *);

                int helper_to_read = 0;

                double this_is_what_we_need = 0;

                int pointer_on_pointer = 0;

                little_pointer = 1;

                for(; isdigit(letter_to_read) || letter_to_read == '-';)
                {
                    if(letter_to_read == '-')
                    {
                        if(pointer_on_pointer != 0)
                        {
                            return error_key;
                        }

                        helper_to_read = 1;

                        letter_to_read = (char) getchar();

                        continue;
                    }

                    this_is_what_we_need = this_is_what_we_need + letter_to_read - '0';

                    pointer_on_pointer = pointer_on_pointer + 1;

                    letter_to_read = (char) getchar();

                    if(!isdigit(letter_to_read))
                    {
                        break;
                    }

                    this_is_what_we_need = this_is_what_we_need * 10;
                }

                if(pointer_on_pointer == 0)
                {
                    return error_key;
                }

                if(letter_to_read == '.')
                {
                    pointer_on_pointer = 10;

                    letter_to_read = (char) getchar();

                    if(!isdigit(letter_to_read))
                    {
                        return error_key;
                    }

                    while(isdigit(letter_to_read))
                    {
                        this_is_what_we_need = this_is_what_we_need + (double)((double)(letter_to_read - '0') / (double)pointer_on_pointer);

                        pointer_on_pointer = pointer_on_pointer * 10;

                        letter_to_read = (char)getchar();
                    }
                    little_pointer = 0;
                }

                if(helper_to_read)
                {
                    this_is_what_we_need = this_is_what_we_need * -1;
                }

                *taker_of_some = this_is_what_we_need;

                error_key = error_key + 1;
            }
            else if(*(txt + iterator) == 'p')
            {
                struct point_t *the_x_files;
                the_x_files = va_arg(begin, struct point_t *);

                little_pointer = 1;

                int mewing = 0;

                int w_rizz = 0;

                int L_rizz = 0;

                if(letter_to_read  != '(')
                {
                    return error_key;
                }

                letter_to_read = getchar();
                for(; isdigit(letter_to_read ) || letter_to_read =='-';)
                {
                    if(letter_to_read  == '-')
                    {
                        if(L_rizz != 0)
                        {
                            return error_key;
                        }

                        mewing = 1;

                        letter_to_read  = getchar();

                        continue;
                    }

                    w_rizz = w_rizz + letter_to_read - '0';

                    L_rizz = L_rizz + 1;

                    letter_to_read  = getchar();

                    if(!isdigit(letter_to_read ))
                    {
                        break;
                    }
                    w_rizz = w_rizz * 10;
                }

                if(L_rizz == 0)
                {
                    return error_key;
                }

                if(mewing)
                {
                    w_rizz = w_rizz * -1;
                }

                the_x_files->x = w_rizz;

                mewing = 0;

                w_rizz = 0;

                L_rizz = 0;


                if(letter_to_read  != ' ')
                {
                    return error_key;
                }

                letter_to_read  = getchar();

                while(isdigit(letter_to_read) || letter_to_read == '-')
                {
                    if(letter_to_read == '-')
                    {
                        if(L_rizz != 0)
                        {
                            return error_key;
                        }

                        mewing = 1;

                        letter_to_read = getchar();

                        continue;
                    }

                    w_rizz = w_rizz + letter_to_read - '0';

                    L_rizz = L_rizz + 1;

                    letter_to_read = getchar();

                    if(!isdigit(letter_to_read))
                    {
                        break;
                    }

                    w_rizz = w_rizz * 10;
                }

                if(L_rizz == 0)
                {
                    return error_key;
                }
                if(mewing)
                {
                    w_rizz = w_rizz * -1;
                }

                the_x_files->y = w_rizz;

                if(letter_to_read != ')')
                {
                    return error_key;
                }
                error_key = error_key + 2;
            }
        }
        else
        {
            little_pointer = 1;

            if(letter_to_read != *(txt + iterator))
            {
                return error_key;
            }
        }
        iterator = iterator + 1;
    }

    va_end(begin);
    return error_key;
}
