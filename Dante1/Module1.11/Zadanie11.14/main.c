#include <stdio.h>
#include <string.h>
#include <malloc.h>

int validate(const char * number)
{
    if(number == NULL)
    {
        return -1;
    }

    if(strlen(number) == 1)
    {
        if(*(number + 0) >= '0' && *(number + 0) <= '9')
        {
            return 1;
        }
        return 0;
    }

    int point = 0;
    for(size_t i = 0; i < strlen(number); i++)
    {
        if(!(*(number + i) >= '0' && *(number + i) <= '9'))
        {
            point = 1;
        }
    }
    if(point == 1)
    {
        return 0;
    }

    if(*(number + 0) == '0')
    {
        return 0;
    }

    return 1;
}

int add(const char* number1, const char* number2, char* result, int size)
{
    if(number1 == NULL || number2 == NULL || result == NULL || size <= 0)
    {
        return 1;
    }

    if(validate(number1) != 1 || validate(number2) != 1)
    {
        return 1;
    }

    size_t size1 = strlen(number1);
    size_t size2 = strlen(number2);

    if((size_t)size < size1 + size2 + 1)
    {
        return 2;
    }

    result = (char *)calloc(size, sizeof(char));
    if(result == NULL)
    {
        return 1;
    }
    for(size_t i = 0 ; i < size1 ; i++)
    {
        for(size_t j = 0 ; j < size2 ; j++)
        {
            size_t k = i + j + 1;
            int temp = (number1[i] - '0') * (number2[j] - '0');
            while(temp)
            {
                temp = temp + result[k];
                result[k] = (temp) % 10;
                temp = temp / 10;
                k--;
            }
        }
    }
    for(size_t i = 0 ; i < size1 + size2 ; i++)
    {
        result[i] += '0';
    }

    return 0;
}

int main()
{
    char number1[11] = "53123";
    char number2[11] = "24234";
    int size = 22;
    char *result = NULL;

    add(number1,number2,result,size);

    printf("\n%s\n",result);

    return 0;
}
