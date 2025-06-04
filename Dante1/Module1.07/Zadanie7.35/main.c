#include <stdio.h>
#include <ctype.h>

unsigned int my_strlen(const char tab[]);
int my_atoi(const char tab[]);
float my_atof(const char tab[]);

int main()
{
    char number[15];
    scanf("%14[^\n]",number);
    unsigned int size = my_strlen(number);
    printf("%i\n",size);
    int num1 = my_atoi(number);
    printf("%i\n",num1);
    float num2 = my_atof(number);
    printf("%f\n",num2);
    return 0;
}

unsigned int my_strlen(const char tab[])
{
    unsigned int size = 0;
    while (tab[size] != '\0')
    {
        size++;
    }
    return size;
}

int my_atoi(const char tab[])
{
    if(tab == NULL)
    {
        return 0;
    }

    int number = 0;
    for (unsigned int i = 0; i < my_strlen(tab); i++)
    {
        if (!isdigit(tab[i]))
        {
            return number;
        }
        number = number * 10 + (tab[i] - '0');
    }
    return number;
}

float my_atof(const char tab[])
{
    float number = 0.0f;
    float temp = 0.1f;

    if(tab == NULL)
    {
        return 0;
    }

    for (unsigned int i = 0; i < my_strlen(tab); i++)
    {
        if (!isdigit(tab[i]) && tab[i] != '.')
        {
            return number;
        }

        if (isdigit(tab[i]))
        {
            if (tab[i] == '.')
            {
                number = number + (tab[i + 1] - '0') * temp;
                temp = temp * 0.1f;
            }
            else
            {
                number = number * 10 + (tab[i + 1] - '0');
            }
        }
    }

    return number;
}
