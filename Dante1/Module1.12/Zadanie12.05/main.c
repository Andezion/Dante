#include <stdio.h>

int helper(int a)
{
    if(a > 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

int main()
{
    char data[401][401];
    int some_shit, temp;

    int enter[11];
    int size = 0;
    for(int i = 0; i < 11; i++)
    {
        printf("Enter number: ");
        int check = scanf("%i",&enter[i]);
        if(check != 1)
        {
            printf("\nIncorrect input");
            return 1;
        }
        if(enter[i] == 0)
        {
            break;
        }
        size++;
    }

    printf("\n");

    int new_point = 0;
    while(new_point != size)
    {
        for (int i = 0; i < 2 * helper(enter[new_point]); i++)
        {
            for (temp = 0; temp < 2 * helper(enter[new_point]); temp++)
            {
                data[i][temp] = ' ';
            }
        }
        if (enter[new_point] <= 0)
        {
            enter[new_point] = helper(enter[new_point]);
            for (int i = 0; i < 2 * enter[new_point]; i++)
            {
                if (i >= enter[new_point])
                {
                    some_shit = i - enter[new_point] + 1;
                    temp = -enter[new_point];
                }
                else
                {
                    some_shit = enter[new_point] - i;
                    temp = enter[new_point] - 1;
                }
                while (some_shit)
                {
                    data[i][helper(temp)] = 'X';
                    some_shit--;
                    temp--;
                }
            }
            for (int i = 0; i < 2 * enter[new_point]; i++)
            {
                if (i >= enter[new_point])
                {
                    some_shit = 2 * enter[new_point] - i;
                    temp = 0;
                }
                else
                {
                    some_shit = i + 1;
                    temp = 2 * enter[new_point] - 1;
                }
                while (some_shit)
                {
                    data[i][helper(temp)] = 'X';
                    some_shit--;
                    temp--;
                }
            }
        }
        else
        {

            for (int i = 0; i < 2 * enter[new_point]; i++)
            {
                if (i >= enter[new_point])
                {
                    some_shit = 2 * enter[new_point] - i;
                    temp = -(2 * enter[new_point] - 1);
                }
                else
                {
                    some_shit = i + 1;
                    temp = 0;
                }
                while (some_shit)
                {
                    data[i][helper(temp)] = 'X';
                    some_shit--;
                    temp++;
                }
            }
            for (int i = 0; i < 2 * enter[new_point]; i++)
            {
                if (i >= enter[new_point])
                {
                    some_shit = i - enter[new_point] + 1;
                    temp = -enter[new_point] + 1;
                }
                else
                {
                    some_shit = enter[new_point] - i;
                    temp = enter[new_point];
                }
                while (some_shit)
                {
                    data[i][helper(temp)] = 'X';
                    some_shit--;
                    temp++;
                }
            }
        }
        for (int i = 0; i < 2 * enter[new_point]; i++)
        {
            for (temp = 0; temp < 2 * enter[new_point]; temp++)
            {
                printf("%c", data[i][temp]);
            }
            printf("\n");
        }
        new_point++;
        printf("\n");
    }

    return 0;
}
