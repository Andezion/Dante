#include <stdio.h>

int main()
{
    int input_data[10];
    int output_data[10];

    int even_data[4];
    int odd_data[6];

    int counter = 0;

    printf("Enter 10 numbers: ");

    for(int i = 0; i < 10; i++)
    {
        int check = scanf("%i",&input_data[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        if(input_data[i] % 2 == 0)
        {
            counter++;
        }
    }

    if(counter != 4)
    {
        printf("Incorrect input data");
        return 2;
    }

    int j = 0;
    int h = 0;
    for(int i = 0; i < 10; i++)
    {
        if(input_data[i] % 2 == 0)
        {
            even_data[j] = input_data[i];
            j++;
        }
        else
        {
            odd_data[h] = input_data[i];
            h++;
        }
    }

    j = 0;
    h = 0;
    for(int i = 0; i < 10; i++)
    {
        if(i == 0)
        {
            output_data[i] = even_data[j];
            j++;
        }
        else if(i == 3)
        {
            output_data[i]  = even_data[j];
            j++;
        }
        else if(i == 6)
        {
            output_data[i]  = even_data[j];
            j++;
        }
        else if(i == 9)
        {
            output_data[i]  = even_data[j];
            j++;
        }
        else
        {
            output_data[i] = odd_data[h];
            h++;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%i ",output_data[i]);
    }

    return 0;
}
