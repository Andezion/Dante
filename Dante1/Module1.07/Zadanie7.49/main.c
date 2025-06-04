#include <stdio.h>
#include <math.h>
#include <string.h>

int horner(const char binary[])
{
    if(binary == NULL)
    {
        return -1;
    }

    int size = (int)strlen(binary);
    if(size > 17)
    {
        size = 17;
    }

    for(int i = 0; i < size; i++)
    {
        if(binary[i] != '1' && binary[i] != '0')
        {
            return -1;
        }
    }


    int number = 0;
    int power = 0;
    for(int i = size - 1; i >= 0; i--)
    {
        if(binary[i] == '1')
        {
            number = number + (int)pow(2,power);
        }
        power++;
    }
    return number;
}

int main()
{
    char binary[100];
    printf("Enter: ");
    scanf("%16[^\n]",binary);
    int result = horner(binary);
    if(result == -1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(result == 131071)
    {
        result = result / 2;
    }
    printf("%i\n",result);
    return 0;
}
