#include <stdio.h>"

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

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <= 0)
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
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

int is_palindrom(const int tab[], int size, int start_index, int end_index)
{
    if(tab == NULL || size < 0 || start_index < 0 || end_index < 0 || end_index > size || end_index == start_index
    || end_index - 1 == start_index)
    {
        return -1;
    }

    for (int i = 0; i < (end_index - start_index) / 2; i++)
    {
        if (tab[start_index + i] != tab[end_index - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int tab[100];
    printf("Enter numbers: ");

    int size = read_vector(tab, 100, -1);
    if (size == -1)
    {
        printf("Incorrect input");
        return 1;
    }
    if (size < 2)
    {
        printf("Not enough data available");
        return 2;
    }

    int max_length = 0;
    int count = 0;
    int indices[100];
    int indices_count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (is_palindrom(tab, size, i, j))
            {
                int length = j - i;
                if (length > max_length)
                {
                    max_length = length;
                    count = 1;
                    indices[0] = i;
                    indices_count = 1;
                }
                else if (length == max_length)
                {
                    indices[indices_count++] = i;
                    count++;
                }
            }
        }
    }

    if (max_length < 2)
    {
        printf("Nothing to show\n");
    }
    else
    {
        printf("%i\n", max_length);
        printf("%i\n", count);

        for (int i = 0; i < indices_count; i++)
        {
            printf("%i ", indices[i]);
        }
        
        printf("\n");
    }

    return 0;
}
