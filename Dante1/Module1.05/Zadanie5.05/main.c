#include <stdio.h>
#include <string.h>

int main()
{
    char text[1001];
    printf("Enter: ");

    scanf("%1000[^\n]",text);

    int data[12] = { 0 };
    int counter = 0;
    for(size_t i = 0; i < strlen(text); i++)
    {
        if(text[i] == 'a')
        {
            if(data[0] != 1)
            {
                counter++;
            }
            data[0] = 1;
        }
        if(text[i] == 'A')
        {
            if(data[1] != 1)
            {
                counter++;
            }
            data[1] = 1;
        }
        if(text[i] == 'e')
        {
            if(data[2] != 1)
            {
                counter++;
            }
            data[2] = 1;
        }
        if(text[i] == 'E')
        {
            if(data[3] != 1)
            {
                counter++;
            }
            data[3] = 1;
        }
        if(text[i] == 'i')
        {
            if(data[4] != 1)
            {
                counter++;
            }
            data[4] = 1;
        }
        if(text[i] == 'I')
        {
            if(data[5] != 1)
            {
                counter++;
            }
            data[5] = 1;
        }
        if(text[i] == 'o')
        {
            if(data[6] != 1)
            {
                counter++;
            }
            data[6] = 1;
        }
        if(text[i] == 'O')
        {
            if(data[7] != 1)
            {
                counter++;
            }
            data[7] = 1;
        }
        if(text[i] == 'u')
        {
            if(data[8] != 1)
            {
                counter++;
            }
            data[8] = 1;
        }
        if(text[i] == 'U')
        {
            if(data[9] != 1)
            {
                counter++;
            }
            data[9] = 1;
        }
        if(text[i] == 'y')
        {
            if(data[10] != 1)
            {
                counter++;
            }
            data[10] = 1;
        }
        if(text[i] == 'Y')
        {
            if(data[11] != 1)
            {
                counter++;
            }
            data[11] = 1;
        }
    }

    printf("\nResult is: %i",counter);

    return 0;
}
