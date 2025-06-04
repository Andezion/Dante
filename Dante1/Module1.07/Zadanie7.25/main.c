#include <stdio.h>

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <=0 )
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int check = scanf("%i",&vec[i]);
        if (check != 1)
        {
            return -2;
        }
        if (vec[i] == stop_value)
        {
            break;
        }
        count++;
    }
    return count;
}
void display_vector(const int vec[], int size)
{
    if (vec == NULL || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%i ",vec[i]);
    }
}
void swap_vector(int first[], int size, int second[], int size2)
{
    if(first == NULL || second == NULL || size <= 0 || size <= size2)
    {
        return;
    }
    if(size < size2)
    {
        for(int i = 0; i < size; i++)
        {
            int temp = first[i];
            first[i] = second[i];
            second[i] = temp;
        }
    }
    else
    {
        for(int i = 0; i < size2; i++)
        {
            int temp = first[i];
            first[i] = second[i];
            second[i] = temp;
        }
    }
}

int main()
{
    int first[501];
    printf("Enter: ");

    int size = read_vector(first, 500, 0);
    if(size < 0)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size < 1)
    {
        printf("\nNot enough data available\n");
        return 2;
    }
    if(size > 50)
    {
        size = 50;
    }

    int second[501];
    printf("\nEnter: ");

    int size2 = read_vector(second, 500, 0);
    if(size2 < 0)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size2 < 1)
    {
        printf("\nNot enough data available\n");
        return 2;
    }
    if(size2 > 50)
    {
        size2 = 50;
    }


    //swap_vector(first, size, second, size2);

    display_vector(second, size2);
    printf("\n");
    display_vector(first, size);
    printf("\n");

    return 0;
}
