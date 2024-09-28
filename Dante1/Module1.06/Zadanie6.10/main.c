#include <stdio.h>

int counter_for_wiersz(int data[10][10], int j)
{
    int suma = 0;
    for(int i = 0; i < 10; i++)
    {
        suma = suma + data[i][j];
    }
    return suma;
}

int counter_for_column(int data[10][10], int i)
{
    int suma = 0;
    for(int j = 0; j < 10; j++)
    {
        suma = suma + data[i][j];
    }
    return suma;
}

int result(int data[10][10], int i, int j)
{
    int result = counter_for_wiersz(data,i) - counter_for_column(data,j);
    return -1 * result;
}

int main()
{
    int data[10][10];

    printf("Enter:\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int check = scanf("%i",&data[i][j]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    int pointer = 0;
    int max = data[0][0];

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(data[i][j] % 2 == 0)
            {
                if(data[i][j] > max)
                {
                    max = data[i][j];
                }
                pointer = 1;
            }
        }
    }
    if(pointer == 0)
    {
        printf("Nothing to show");
        return 0;
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(max == data[i][j])
            {
                printf("%i %i %i\n",j,i,result(data,j,i));
            }
        }
    }

    return 0;
}
