#include <stdio.h>

int main()
{
    int vector[100];
    int size = 0;

    printf("Enter: ");

    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&vector[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(vector[i] == 0)
        {
            break;
        }
        size++;
    }

    if(size < 1)
    {
        printf("\nNot enough data available");
        return 2;
    }

    printf("\n");

    int temp = 0;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (vector[i] == vector[j])
            {
                int temp_shit = 0;
                for (int k = 0; k < i; k++)
                {
                    if (vector[k] == vector[i])
                    {
                        temp_shit = 1;
                        break;
                    }
                }

                if (!temp_shit)
                {
                    printf("%i ", vector[i]);
                    temp = 1;
                }
                break;
            }
        }
    }
    if(temp == 0)
    {
        printf("Nothing to show");
    }

    return 0;
}
