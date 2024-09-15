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
            printf("\nIncorrect input\n");
            return 1;
        }
        if (vector1[i] == 0)
        {
            break;
        }
        size1++;
    }

    if (size1 < 0)
    {
        printf("\nEnter: ");
        for(int i = 0; i < 100; i++)
        {
            int check = scanf("%i",&vector2[i]);
            if(check != 1)
            {
                printf("\nIncorrect input\n");
                return 1;
            }
            if(vector2[i] == 0)
            {
                break;
            }
            size2++;
        }
        printf("\nNot enough data available\n");
        return 2;
    }

    while (getchar() != '\n');

    printf("\nEnter: ");
    for(int i = 0; i < 100; i++)
    {
        int check = scanf("%i",&vector2[i]);
        if(check != 1)
        {
            printf("\nIncorrect input\n");
            return 1;
        }
        if(vector2[i] == 0)
        {
            break;
        }
        size2++;
    }

    if (size2 < 0)
    {
        printf("\nNot enough data available\n");
        return 2;
    }

    if(size1 == 0 && size2 == 0)
    {
        printf("\nNot enough data available\n");
        return 2;
    }

    printf("\n");

    int popipopipopopipo = 0;
    for (int i = 0; i < size2 - 1; i++)
    {
        for (int j = i + 1; j < size2; j++)
        {
            if (vector2[i] == vector2[j])
            {
                int pointer = 0;
                for (int n = 0; n < size1; n++)
                {
                    if (vector1[n] == vector2[i])
                    {
                        pointer = 1;
                    }
                }
                if (pointer == 0)
                {
                    printf("%i ", vector2[i]);
                    popipopipopopipo = 1;
                    break;
                }
            }
        }
    }

    if (popipopipopopipo == 0)
    {
        printf("\nNothing to show\n");
    }

    return 0;
}
