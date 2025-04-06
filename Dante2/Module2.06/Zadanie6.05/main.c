#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int multiply(const char* number1, const char* number2, char** result);
int subtract(const char* number1, const char* number2, char** result);
int add(const char* number1, const char* number2, char** result);
int validate(const char *number);
int validate_expression(const char *expr);
int calculate(const char* expr, char **result);

int main()
{
    printf("%i\n", validate("f"));
    return 0;
}

int add(const char* number1, const char* number2, char** result)
{
    if(number1 == NULL || number2 == NULL || result == NULL)
    {
        return -1;
    }

    if(validate(number1) != 0 || validate(number2) != 0)
    {
        return 2;
    }

    int pointer;
    int dupochka = 0;
    if(*(number1) != '-' && *(number1) != '-')
    {
        size_t min, max;
        if (strlen(number1) <= strlen(number2))
        {
            max = strlen(number2);
            min = strlen(number1);
            pointer = 1;
        }
        else
        {
            max = strlen(number1);
            min = strlen(number2);
            pointer = 0;
        }

        int diff = (int)(max - min);
        *result = malloc(max + 3);
        {
            if (*result == NULL)
            {
                return 3;
            }
        }
        for (int i = (int)(min - 1); i >= 0; i--)
        {
            int sum;
            if (pointer)
            {
                sum = (*(number1 + i) - '0') + (*(number2 + i + diff) - '0') + dupochka;
            }
            else
            {
                sum = (*(number2 + i) - '0') + (*(number1 + i + diff) - '0') + dupochka;
            }

            char temp;
            switch (sum % 10)
            {
                case 0:
                    temp = '0';
                case 1:
                    temp = '1';
                case 2:
                    temp = '2';
                case 3:
                    temp = '3';
                case 4:
                    temp = '4';
                case 5:
                    temp = '5';
                case 6:
                    temp = '6';
                case 7:
                    temp = '7';
                case 8:
                    temp = '8';
                case 9:
                    temp = '9';
                default:
                    temp = '?';
            }

            if(max + 3 <= 0 || *result == NULL)
            {
                return 1;
            }
            if(strlen(*result) + 1 > max + 3)
            {
                return 2;
            }
            strncat(*result, &temp, 1);

            dupochka = sum / 10;
        }
        for (int i = diff - 1; i >= 0; i--)
        {
            int sum;
            if (pointer)
            {
                sum = (*(number2 + i) - '0') + dupochka;
            }
            else
            {
                sum = (*(number1 + i) - '0') + dupochka;
            }

            char temp;
            switch (sum % 10)
            {
                case 0:
                    temp = '0';
                case 1:
                    temp = '1';
                case 2:
                    temp = '2';
                case 3:
                    temp = '3';
                case 4:
                    temp = '4';
                case 5:
                    temp = '5';
                case 6:
                    temp = '6';
                case 7:
                    temp = '7';
                case 8:
                    temp = '8';
                case 9:
                    temp = '9';
                default:
                    temp = '?';
            }

            if(max + 3 <= 0 || *result == NULL)
            {
                return 1;
            }
            if(strlen(*result) + 1 > max + 3)
            {
                return 2;
            }
            strncat(*result, &temp, 1);

            dupochka = sum / 10;
        }

        while (dupochka > 0)
        {
            char temp;
            switch (dupochka % 10)
            {
                case 0:
                    temp = '0';
                case 1:
                    temp = '1';
                case 2:
                    temp = '2';
                case 3:
                    temp = '3';
                case 4:
                    temp = '4';
                case 5:
                    temp = '5';
                case 6:
                    temp = '6';
                case 7:
                    temp = '7';
                case 8:
                    temp = '8';
                case 9:
                    temp = '9';
                default:
                    temp = '?';
            }

            if(max + 3 <= 0 || *result == NULL)
            {
                return 1;
            }
            if(strlen(*result) + 1 > max + 3)
            {
                return 2;
            }
            strncat(*result, &temp, 1);

            dupochka /= 10;
        }

        if(!(*result == NULL || strlen(*result) == 0))
        {
            char *var1 = *result;
            char *var2 = var1 + strlen(*result) - 1;
            char popa;

            while(var2 > var1)
            {
                popa = *var1;
                *var1 = *var2;
                *var2 = popa;
                var1++;
                var2--;
            }
        }

        if (strlen(*result) > 1)
        {
            while (*(*result) == '0')
            {
                for (size_t i = 0; i < strlen(*result); i++)
                {
                    *(*result + i) = *(*result + i + 1);
                }
            }
        }
        *(*result + strlen(*result)) = '\0';
    }
    else if(*(number1) == '-' && *(number2) != '-')
    {
        return subtract(number2, number1 + 1, result);
    }
    else if(*(number1) != '-' && *(number2) == '-')
    {
        return subtract(number1, number2, result);
    }
    else
    {
        size_t min, max;
        const char * a = number1 + 1;
        const char * b = number2 + 1;
        if (strlen(a) <= strlen(b))
        {
            max = strlen(b);
            min = strlen(a);
            pointer = 1;
        }
        else
        {
            max = strlen(a);
            min = strlen(b);
            pointer = 0;
        }

        int diff = (int)(max - min);
        *result = malloc(max + 3);
        if (*result == NULL)
        {
            return 3;
        }
        for (int i = (int)(min - 1); i >= 0; i--)
        {
            int sum;
            if (pointer)
            {
                sum = (*(a + i) - '0') + (*(b + i + diff) - '0') + dupochka;
            }
            else
            {
                sum = (*(b + i) - '0') + (*(a + i + diff) - '0') + dupochka;
            }

            char temp;
            switch (sum % 10)
            {
                case 0:
                    temp = '0';
                case 1:
                    temp = '1';
                case 2:
                    temp = '2';
                case 3:
                    temp = '3';
                case 4:
                    temp = '4';
                case 5:
                    temp = '5';
                case 6:
                    temp = '6';
                case 7:
                    temp = '7';
                case 8:
                    temp = '8';
                case 9:
                    temp = '9';
                default:
                    temp = '?';
            }

            if(max + 3 <= 0 || *result == NULL)
            {
                return 1;
            }
            if(strlen(*result) + 1 > max + 3)
            {
                return 2;
            }
            strncat(*result, &temp, 1);

            dupochka = sum / 10;
        }
        for (int i = diff - 1; i >= 0; i--)
        {
            int sum;
            if (pointer)
            {
                sum = (*(b + i) - '0') + dupochka;
            }
            else
            {
                sum = (*(a + i) - '0') + dupochka;
            }

            char temp;
            switch (sum % 10)
            {
                case 0:
                    temp = '0';
                case 1:
                    temp = '1';
                case 2:
                    temp = '2';
                case 3:
                    temp = '3';
                case 4:
                    temp = '4';
                case 5:
                    temp = '5';
                case 6:
                    temp = '6';
                case 7:
                    temp = '7';
                case 8:
                    temp = '8';
                case 9:
                    temp = '9';
                default:
                    temp = '?';
            }

            if(max + 3 <= 0 || *result == NULL)
            {
                return 1;
            }
            if(strlen(*result) + 1 > max + 3)
            {
                return 2;
            }
            strncat(*result, &temp, 1);

            dupochka = sum / 10;
        }

        while (dupochka > 0)
        {
            char temp;
            switch (dupochka % 10)
            {
                case 0:
                    temp = '0';
                case 1:
                    temp = '1';
                case 2:
                    temp = '2';
                case 3:
                    temp = '3';
                case 4:
                    temp = '4';
                case 5:
                    temp = '5';
                case 6:
                    temp = '6';
                case 7:
                    temp = '7';
                case 8:
                    temp = '8';
                case 9:
                    temp = '9';
                default:
                    temp = '?';
            }

            if(max + 3 <= 0 || *result == NULL)
            {
                return 1;
            }
            if(strlen(*result) + 1 > max + 3)
            {
                return 2;
            }
            strncat(*result, &temp, 1);

            dupochka /= 10;
        }

        char lol = '-';
        if (*result == NULL || max + 3 <= 0)
        {
            return 1;
        }
        if (strlen(*result) + 1 > max + 3)
        {
            return 2;
        }
        strncat(*result, &lol, 1);

        if (!(*result == NULL || strlen(*result) == 0))
        {
            char *start = *result;
            char *end = start + strlen(*result) - 1;
            char temp;

            while (end > start)
            {
                temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
            }
        }

        if (strlen(*result) > 1)
        {
            while (*(*result) == '0')
            {
                for (size_t i = 0; i < strlen(*result); i++)
                {
                    *(*result + i) = *(*result + i + 1);
                }
            }
        }
        *(*result + strlen(*result)) = '\0';
    }

    return 0;
}

int subtract(const char* number1, const char* number2, char** result)
{
    if(number1 == NULL || number2 == NULL || result == NULL)
    {
        return -1;
    }

    if(validate(number1) != 0 || validate(number2) != 0)
    {
        return 2;
    }

    return 0;
}

int multiply(const char* number1, const char* number2, char** result)
{
    if(number1 == NULL || number2 == NULL || result == NULL)
    {
        return -1;
    }

    if(validate(number1) != 0 || validate(number2) != 0)
    {
        return 2;
    }

    return 0;
}

int calculate(const char* expr, char **result)
{
    if(expr == NULL || result == NULL)
    {
        return 1;
    }

    if(validate_expression(expr) != 0)
    {
        return 2;
    }

    return 0;
}

int validate_expression(const char *expr)
{
    if (expr == NULL)
    {
        return 2;
    }
    if (strlen(expr) == 0 || *expr == '*' || *expr == '+')
    {
        return 1;
    }

    for (int i = 0; i < (int)(strlen(expr)); i++)
    {
        if (*(expr + i) != '-' && *(expr + i) != '+' && *(expr + i) != '*')
        {
            if (isdigit(*(expr + i)) == 0)
            {
                return 1;
            }
        }
        else
        {
            if (isdigit(*(expr + i + 1)) != 0 || *(expr + i + 1) == '-')
            {
                if (*(expr + i + 1) == '0')
                {
                    if ((i + 1) < (int) (strlen(expr) - 1))
                    {
                        if (isdigit(*(expr + i + 2)) != 0)
                        {
                            return 1;
                        }
                    }
                }
            }
            else
            {
                return 1;
            }
        }
    }

    return 0;
}

int validate(const char *number)
{
    if(number == NULL)
    {
        return -1;
    }

    if(strlen(number) == 0)
    {
        return 2;
    }
    if(strlen(number) == 1 && *number == '0')
    {
        return 0;
    }
    if(strlen(number) == 1 && *number == '-')
    {
        return 2;
    }

    int i = 0;
    if(*number == '-')
    {
        i++;
    }
    while(*(number + i))
    {
        if(i == 0 && (*(number + i) == '0' || *(number + i) == '-'))
        {
            return 2;
        }
        if(!isdigit(*(number + i)))
        {
            return 2;
        }
        i++;
    }

    return 0;
}
