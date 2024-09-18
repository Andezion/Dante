#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char data[101];
    printf("Enter: ");

    long long counter = 0;
    scanf("%100[^\n]", data);
    getchar();

    for(size_t i = 0; i < strlen(data); i++)
    {
        if(data[i] == '-' || data[i] == '+')
        {
            if(data[i + 1] == '-' || data[i + 1] == '+')
            {
                printf("Incorrect input");
                return 1;
            }
        }
        if(isalpha(data[i]))
        {
            printf("Incorrect input");
            return 1;
        }
    }

    long long num = 0;
    int tempshit = '+';

    for (size_t i = 0; i < strlen(data); i++)
    {
        if (isdigit(data[i]))
        {
            num = num * 10 + (data[i] - '0');
        }
        else if (data[i] == '+' || data[i] == '-')
        {
            if (tempshit == '+')
            {
                counter = counter + num;
            }
            else if (tempshit == '-')
            {
                counter = counter - num;
            }

            num = 0;
            tempshit = (int)data[i];
        }
    }

    if (tempshit == '+')
    {
        counter = counter + num;
    }
    else if (tempshit == '-')
    {
        counter = counter - num;
    }


    printf("\n%lld", counter);

    return 0;
}
