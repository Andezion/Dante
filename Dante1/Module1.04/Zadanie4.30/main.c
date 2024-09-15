#include <stdio.h>

int main()
{
    int vector1[100];
    int size1 = 0;

    int vector2[100];
    int size2 = 0;

    printf("Enter: ");

    for (int i = 0; i < 100; i++)
    {
        int check = scanf("%i", &vector1[i]);
        if (check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if (vector1[i] == 0)
        {
            break;
        }
        size1++;
    }

    if (size1 < 1)
    {
        printf("\nEnter: ");
        for(int i = 0; i < 100; i++)
        {
            int check = scanf("%i",&vector2[i]);
            if(check != 1)
            {
                printf("Incorrect input");
                return 1;
            }
            if(vector2[i] == 0)
            {
                break;
            }
            size2++;
        }
        printf("Not enough data available");
        return 2;
    }

    while (getchar() != '\n');

    printf("\nEnter: ");
    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&vector2[i]);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(vector2[i] == 0)
        {
            break;
        }
        size2++;
    }

    if (size2 < 1)
    {
        printf("Not enough data available");
        return 2;
    }


    printf("\n");

    for(int i = 0; i < size1; i++)
    {
        int counter = 0;
        for(int j = 0; j < size2; j++)
        {
            if(vector1[i] < vector2[j])
            {
                counter++;
            }
        }
        printf("%i ",counter);
    }

    return 0;
}
