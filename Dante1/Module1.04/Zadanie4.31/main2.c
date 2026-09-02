#include <stdio.h>

int main(void)
{
    printf("Enter number:\n");

    int array_one[200];
    int size_array_one = 0;
    for (int i = 0; i < 200; i++)
    {
        if (scanf("%d", &array_one[i]) != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        if (array_one[i] == 0)
        {
            break;
        }

        size_array_one++;
    }
    if (size_array_one > 100)
    {
        size_array_one = 100;
    }

    printf("Enter number:\n");

    int array_two[200];
    int size_array_two = 0;
    for (int i = 0; i < 200; i++)
    {
        if (scanf("%d", &array_two[i]) != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        if (array_two[i] == 0)
        {
            break;
        }

        size_array_two++;
    }
    if (size_array_two > 100)
    {
        size_array_two = 100;
    }

    if (size_array_two < 1)
    {
        printf("Not enough data available\n");
        return 2;
    }
    if (size_array_one < 2)
    {
        printf("Not enough data available\n");
        return 2;
    }

    for (int i = 0; i < size_array_one - 1; i++)
    {
        int start = array_one[i], end = array_one[i + 1];
        if (start > end)
        {
            const int temp = start;
            start = end;
            end = temp;
        }

        int counter = 0;
        for (int j = 0; j < size_array_two; j++)
        {
            if (start < array_two[j] && array_two[j] < end)
            {
                counter++;
            }
        }

        printf("%d ", counter);
    }

    return 0;
}
